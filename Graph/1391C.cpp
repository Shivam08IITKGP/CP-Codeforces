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
ll MOD=1e9+7;
// answer is n! - 2^(n-1)
// Link -> https://codeforces.com/blog/entry/81265
void solve()
{
    ll n;
    cin>>n;

    ll a= 1;
    f(i,2,n+1)
    {
        a=(a*i)%MOD;
    }
    ll b= 1;
    f(i,0,n-1)
    {
        b=(b*2)%MOD;
    }
    a = (a-b+MOD)%MOD;
    cout<<a<<endl;


}

int main()
{
    FAST;
    int t;
    t=1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}
