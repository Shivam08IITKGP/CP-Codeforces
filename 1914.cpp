#include <iostream>
#include <vector>
using namespace std;

#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long int ll;

void solve();
void best_3(vector<ll> &a, int n, int *ans);

int main()
{
    FAST;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n), b(n), c(n);

    // Input
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    for (int i = 0; i < n; i++)
        cin >> c[i];

    ll ans = 0;

    int *best_a = new int[3];
    int *best_b = new int[3];
    int *best_c = new int[3];

    best_3(a, n, best_a);
    best_3(b, n, best_b);
    best_3(c, n, best_c);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                if (best_a[i] != best_b[j] && best_b[j] != best_c[k] && best_c[k] != best_a[i])
                {
                    ans = max(ans, a[best_a[i]] + b[best_b[j]] + c[best_c[k]]);
                }
            }
        }
    }
    delete[] best_a;
    delete[] best_b;
    delete[] best_c;

    cout << ans << "\n";
}

void best_3(vector<ll> &a, int n, int *ans)
{
    ans[0] = -1;
    ans[1] = -1;
    ans[2] = -1;
    for (int i = 0; i < n; i++)
    {
        if (ans[0] == -1 || a[i] > a[ans[0]])
        {
            ans[2] = ans[1];
            ans[1] = ans[0];
            ans[0] = i;
        }
        else if (ans[1] == -1 || a[i] > a[ans[1]])
        {
            ans[2] = ans[1];
            ans[1] = i;
        }
        else if (ans[2] == -1 || a[i] > a[ans[2]])
        {
            ans[2] = i;
        }
    }
}
