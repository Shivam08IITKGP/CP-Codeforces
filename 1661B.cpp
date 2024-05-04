
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define f(i, start, end) for (ll i = start; i < end; i++)
#define fr(i, start, end) for (ll i = start; i > end; i--)
#define vll vector<ll>
#define pll pair<ll, ll>
#define vi vector<int>
#define v vector
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long int ll;

void solve()
{
    int n;
    cin>>n;
  //max ans is 15 because (n * 2^15) mod 2^15 =0 always
  //v→2v→2v+2 can be replaced by v→v+1→2(v+1)
    ll ans= 15;
    f(i,0,15)
    {
        f(j,0,15)
        {
            if((n+i)*(1<<j)%32768==0)
            {
                ans=min(ans,i+j);
            }
        }
    }
    cout<<ans<<" ";
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
