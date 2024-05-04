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

void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> a(n, vector<ll>(m));
    f(i, 0, n)
        f(j, 0, m)
    {
        cin >> a[i][j];
    }
    if (n == 1)
    {
        cout << 0 << endl;
        return;
    }
    vll c(n);
    ll ans = 0;
    f(i, 0, m)
    {
        f(j, 0, n)
        {
            c[j] = a[j][i];
        }
        sort(c.begin(), c.end());
        f(j, 0, n)
        {
            ans = ans + c[j] * (j)-c[j] * (n - 1 - j);
        }
    }
    cout << ans << endl;
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
//First number subtract n-1 times
//Second number subtract n-2 times add 1 time
//Third Number subtract n-3 times and add 2 times
//Last number add n-1 times
