// Link -> https://www.youtube.com/watch?v=wYLJGxY3X08
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

vll dp;
void solve()
{
    ll n;
    cin >> n;
    vll a(n);
    f(i, 0, n)
    {
        cin >> a[i];
    }
    dp.assign(n+1,0);
    dp[n]=0;
    dp[n-1]=1;

    fr(i,n-2,-1)
    {
        ll take =INT_MAX;
        if(a[i]+i<n) take= dp[a[i]+i+1];
        ll nottake= dp[i+1]+1;
        dp[i]=min(take,nottake);
    }    
    cout << dp[0] << endl;
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
