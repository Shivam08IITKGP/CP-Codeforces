#include <bits/stdc++.h>
using namespace std;
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long int ll;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;
    string s;
    cin >> s;

    int index = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == 'L')
        {
            index++;
        }
    }
    vector<int> ans(n);
    ans[n - 1] = a[index] % m;
    int l = index, r = index;
    int i;
    for (i = n - 2; i >= 0; i--)
    {
        if (s[i] == 'L')
        {
            l--;
            ans[i] = (ans[i + 1] * a[l]) % m;
            if (ans[i] == 0)
            {
                break;
            }
        }
        else
        {
            r++;

            ans[i] = (ans[i + 1] * a[r]) % m;
            if (ans[i] == 0)
            {
                break;
            }
        }
    }
    for (; i >= 0; i--)
    {
        ans[i] = 0;
    }
    for (int x : ans)
    {
        cout << x << " ";
    }
    cout << endl;
}

int main()
{
    FAST;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
