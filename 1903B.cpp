#include <bits/stdc++.h>
using namespace std;
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long int ll;
void solve();
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
void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> m(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> m[i][j];
    vector<int> a(n, (1 << 30) - 1);
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
        {
            a[i] &= m[i][j];
            a[j] &= m[i][j];
        }
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
        {
            if ((a[i] | a[j]) != m[i][j])
            {
                cout << "NO\n";
                return;
            }
        }
    cout << "YES\n";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
    return;
}
