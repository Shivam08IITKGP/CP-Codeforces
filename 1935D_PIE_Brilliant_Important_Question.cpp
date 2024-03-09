#include <bits/stdc++.h>
using namespace std;
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long int ll;

void solve()
{
    ll n, c;
    cin >> n >> c;
    vector<ll> a(n);
    ll even = 0, odd = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] % 2 == 0)
            even++;
        else
            odd++;
    }
    ll ans = 0;
    // Principle Of Inclusion and Exclusion

    // ans = cnt(all possible (x,y)) -
    // cnt(all possible (x,y) : x+y =a[i]) -
    // cnt(all possible (x,y): y-x =a[i]) +
    // cnt(all possible (x,y) : x+y =a[i] and y-x =a[j])

    //  considering x<=y
    // + cnt(all possible (x,y))
    // number of such pairs will be (c+1)C2
    ans += (c + 1) * (c + 2) / 2;

    // - cnt(all possible (x,y) : x+y =a[i])
    // number of such pairs will be ceil(a[i]/2) + 1
    for (ll i = 0; i < n; i++)
    {
        ans -= a[i] / 2 + 1;
    }
    // - cnt(all possible (x,y): y-x =a[i])
    // number of such pairs will be c - a[i] + 1
    for (ll i = 0; i < n; i++)
    {
        ans -= (c - a[i] + 1);
    }

    // + cnt(all possible (x,y) : x+y =a[i] and y-x =a[j])
    // This is only possible if a[i] and a[j] are of same parity
    ans += even * (even + 1) / 2 + odd * (odd + 1) / 2;
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
    return 0;
}
