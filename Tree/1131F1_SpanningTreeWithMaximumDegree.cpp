#include <bits/stdc++.h>
using namespace std;

#define f(i, start, end) for (int i = start; i < end; i++)
#define fr(i, start, end) for (int i = start; i > end; i--)
typedef long long int ll;

vector<int> adj[20001];
vector<int> vis;

void bfs(int src)
{
    vis[src] = 1;
    queue<int> q;
    q.push(src);
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto child : adj[node])
        {
            if (!vis[child])
            {
                vis[child] = 1;
                q.push(child);
                cout << node << " " << child << endl;
            }
        }
    }
}

void solve()
{
    int a, b, maxDegree = 0, maxNode = -1;
    int n, m;
    cin >> n >> m;
    vis.assign(n + 1, 0);
    f(i, 0, m)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    f(i, 1, n + 1)
    {
        if (maxDegree < adj[i].size())
        {
            maxDegree = adj[i].size();
            maxNode = i;
        }
    }
    bfs(maxNode);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    // cin >> t;
    t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}
