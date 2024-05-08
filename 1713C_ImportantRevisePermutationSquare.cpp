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
vll ans;
void recurse(ll r)
{
    if(r<0) return;
    ll s= sqrt(2*r);
    s*=s;
    ll l = s-r;
    recurse(l-1);
    for(;l<=r;l++,r--)
    {
        ans[l]=r;
        ans[r]=l;
    }
}
void solve()
{
    ll n;
    cin>>n;
    ans.resize(n);
    recurse(n-1);
    f(i,0,n)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;

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
