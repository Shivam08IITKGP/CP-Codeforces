//Time complexity is O(nlogn)
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
void solve()
{
    ll n, x, y;
    cin >> n >> x >> y;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    ll ans = 0;
    map<pair<ll,ll>,ll>m;
    for(ll i=0;i<n;i++)
    {
        ll a= v[i]%x;
        ll b= v[i]%y;
        ll p= (x-a)%x;//Very Important
        ll q= (b)%y;  //Very Important
        ans+= m[{p,q}];
        m[{a,b}]++;
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
    return 0;
}
