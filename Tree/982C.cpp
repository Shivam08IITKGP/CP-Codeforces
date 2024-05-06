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

vector<int> adj[100001];
vector<int> nodes;
vector<int> visited;
void dfs(int node)
{
    for (auto child : adj[node])
    {
        if (!visited[child])
        {
            visited[child] = 1;
            dfs(child);
            nodes[node] += nodes[child];
        }
    }
}
void solve()
{
    ll n;
    cin >> n;
    if (n & 1)
    {
        f(i, 0, n - 1)
        {
            int u, v;
            cin >> u >> v;
        }
        cout << -1 << endl;
        return;
    }
    f(i, 0, n - 1)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int ans = 0;
    nodes.assign(n + 1, 1);
    visited.assign(n + 1, 0);
    visited[1] = 1;
    dfs(1);
    f(i, 2, n + 1)
    {
        if (nodes[i] % 2 == 0)
        {
            ans++;
        }
    }
    // f(i,1,n+1)
    // {
    //     cout<<nodes[i]<<" ";
    // }
    // cout<<endl;
    cout << ans << endl;
}

int main()
{
    FAST;
    int t;
    // cin >> t;
    t=1;
    while (t--)
    {
        solve();
    }
}
