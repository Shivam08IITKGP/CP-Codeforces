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

    ll x, y;
    vector<ll> r(n+1, n);
    while (m--)
    {
        cin >> x >> y;
        if (x > y)
        {
            swap(x, y);
        }
        r[x] = min(r[x], y - 1);
    }

    for(ll i=n-1;i>0;i--)
    {
        r[i]=min(r[i],r[i+1]);
    }
    ll ans= 0;
    for(ll i=0;i<n;i++)
    {
        ans+= r[i]-i;
    }
    cout<<ans<<endl;
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
