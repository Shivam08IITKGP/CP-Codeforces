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

vector<char> color(200005);
vector<pair<int, int>> dp(200005);
vector<int> child[200005];
//child is another way to form a tree

void dfs(int u)
{
    if(color[u]=='B')
    {
        dp[u].second++;
    }
    else
    {
        dp[u].first++;
    }
    for(auto child:child[u])
    {
        dfs(child);
    }
    for(auto child:child[u])
    {
        dp[u].first+=dp[child].first;
        dp[u].second+=dp[child].second;
    }
}

void solve()
{
    int n;
    cin >> n;
    int u;
    for(int i=1;i<=n;i++)
    {
        child[i].clear();
        dp[i].first=0;
        dp[i].second=0;
    }
    for(int i=0;i<n-1;i++)
    {
        cin>>u;
        child[u].push_back(i+2);
    }

    for(int i=1;i<=n;i++)
    {
        char c;
        cin>>c;
        color[i]=c;
    }
    dfs(1);
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(dp[i].first==dp[i].second)
        {
            ans++;

        }
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
