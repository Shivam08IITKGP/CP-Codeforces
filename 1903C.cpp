#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long int ll;

void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<ll>suffix(n);
    suffix[n-1]=a[n-1];
    for(int i=n-2;i>=0;i--){
        suffix[i]=suffix[i+1]+a[i];
    }
    ll ans=suffix[0];
    for(int i=1;i<n;i++)
    {
        if(suffix[i]>0)
        {
            ans+=suffix[i];
        }
    }
    cout<<ans<<"\n";
}
int main()
{
    FASTIO
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
