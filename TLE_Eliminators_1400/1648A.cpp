#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define f(i, start, end) for (ll i = start; i < end; i++)
#define fr(i, start, end) for (ll i = start; i > end; i--)
#define vll vector<ll>
#define pll pair<ll, ll>
#define vi vector<int>
#define v vector
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long int ll;
vll row[100001];
vll col[100001];

void solve()
{
    ll n, m;
    cin >> n >> m;
    v<vll> a(n, vll(m, 0));
    ll C = 0;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            cin >> a[i][j];
            C=max(C,a[i][j]);
            col[a[i][j]].push_back(i);
        }
    }
    for (ll j = 0; j < m; j++)
    {
        for (ll i = 0; i < n; i++)
        {
            row[a[i][j]].push_back(j);
        }
    }
    ll ans = 0;
    // for(int i=0;i<col[4].size();i++)
    // {
    //     cout<<col[4][i]<<" ";
    // }
    // cout<<endl;
    // for(int i=0;i<row[4].size();i++)
    // {
    //     cout<<row[4][i]<<" ";
    // }
    // cout<<endl;


    for (ll c = 1; c <= C; c++)
    {
        for (ll i = 0; i < col[c].size(); i++)
        {
            ans += (2 * i + 1 - col[c].size()) * (col[c][i]);
        }
        for (ll i = 0; i < row[c].size(); i++)
        {
            ans += (2 * i + 1 - row[c].size()) * (row[c][i]);
        }
    }
    cout << ans << endl;
}

int main()
{
    FAST;
    int t;
    // cin >> t;
    t = 1;
    while (t--)
    {
        solve();
    }
}
