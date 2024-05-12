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
    ll n, k, q;
    cin >> n >> k >> q;
    // a.resize(n);
    ll a[k + 1];
    a[0] = 0;
    ll b[k + 1];
    b[0] = 0;
    f(i, 0, k)
    {
        cin >> a[i + 1];
    }
    // b.resize(n);
    f(i, 0, k)
    {
        cin >> b[i + 1];
    }
    while (q--)
    {
        ll p;
        cin >> p;
        if (p == 0)
        {
            cout << 0 << " ";
            continue;
        }
        if (p == n)
        {
            cout << b[k] << " ";
            continue;
        }

        auto x = upper_bound(a, a + k + 1, p) - a;
        x--;
        ll ans = b[x];
        if (p > a[x])
        {
          //For this I have been using double, long double, nothingworked
          // Long long is working but.
            ans += (p - a[x]) * (b[x + 1] - b[x]) / (a[x + 1] - a[x]);
        }
        cout << ans << " ";
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
