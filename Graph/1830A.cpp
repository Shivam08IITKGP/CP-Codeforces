#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

//dp[i] is the number of scans reqquired to activate the node i.
//id[i] is the index of the edge where the node i gets activated.

//Pair's first element is the node and the second one is the edge's index.
//Now first scan the store the vertices and edges in the edge vec pair.

// Now start dfs from the root.
// 2 cases (only when v is not visited.)
//1) 
//index(u,v) >= id[u], i.e. we can visit v in the same scan as u (this edge is greater than where u will be activated)
// Hence dp[v]=dp[u] and id[v]= index(u,v)
//2)
//index(u,v)<id[u],i.e.v will be visited in the next scan after dp[u](this edge is before the edge where u will be activated)
// dp[v]=dp[u]+1 and id[v]=index(u,v)
vector<int>dp(2e5+5),id(2e5+5);
vector<pair<int,int>>edge[200005];
void dfs(int node)
{
    for(auto it: edge[node])
    {
      //it.first is v, it.second is edge(u,v)'s index
        if(dp[it.first]!=0) continue;
        dp[it.first]=dp[node]+(it.second<id[node]);
        id[it.first]=it.second;
        dfs(it.first);
    }
}
void solve()
{
    int n;
    cin>>n;
    for(int i=0;i<=n;i++)
    {
        dp[i]=0, id[i]=0;
        edge[i].clear();
    }
    int u,v;
    dp[1]=1;
    for(int i=0;i<n-1;i++)
    {
        cin>>u>>v;
        edge[u].push_back({v,i});
        edge[v].push_back({u,i});
    }
    dfs(1);
    int ans= 0;
    for(int i=1;i<=n;i++)
    {
        ans=max(ans,dp[i]);
    }
    cout<<ans<<endl;
    
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}
