#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define f(i, start, end) for (ll i = start; i < end; i++)
#define fr(i, start, end) for (ll i = start; i > end; i--)
#define vll vector<ll>
#define pll pair<ll, ll>
#define vi vector<int>
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long int ll;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> adj[n + 1];
    vector<int> marked;
    f(i, 0, k)
    {
        int x;
        cin >> x;
        marked.pb(x);
    }

    f(i, 1, n)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    if(k==1)
    {
        cout<<0<<endl;
        return;
    }
    vector<int>d1(n+1,0);
    function<void(int,int)>dfs=[&](int node,int parent)
    {
        if(parent!=-1)
        {
            d1[node]=d1[parent]+1;
        }
        for(auto child:adj[node])
        {
            if(child!=parent)
            {
                dfs(child,node);
            }
        }
    };
    //marked[0] is v1
    dfs(marked[0],-1);
    int maxi= marked[0];
    for(auto it: marked)
    {
        if(d1[it]>d1[maxi])
        {
            maxi=it;
        }
    }
    // maxi is v2
    // cout<<maxi<<endl<<endl;
    d1.assign(n+1,0);

    dfs(maxi,-1);
    maxi= marked[0];
    for(auto it: marked)
    {
        if(d1[it]>d1[maxi])
        {
            maxi=it;
        }
    }
    // maxi is v3
    cout<<(d1[maxi]+1)/2<<endl;



}

int main()
{
    FAST;
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
