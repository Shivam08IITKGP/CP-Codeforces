https://codeforces.com/blog/entry/128116

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define f(i, start, end) for (ll i = start; i < end; i++)
#define fr(i, start, end) for (ll i = start; i > end; i--)
#define vll vector<ll>
#define pll pair<ll, ll>
#define vi vector<int>
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long int ll;
#define int long long

void solve()
{
    int n,m,k;
    cin>>n>>m>>k;
    vi a(n);
    f(i,0,n)
    {
        cin>>a[i];
    }
    sort(begin(a),end(a));
    int ans=0;
    for(int i=0,cnt=0;i<n and cnt<=k;i++)
    {
        int current=min(m, k-cnt);
        ans+= ((a[i]+ cnt)*current);
        cnt+= current;
    }
    cout<<ans<<endl;    
    // We will buy the maximum tickets at the days where the initial cost is the lowest 
    // As the cost increases by the number of tickets purchased amount
    //For math proof look at the link
}

signed main()
{
    FAST;
    int t=1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
