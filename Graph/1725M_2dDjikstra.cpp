#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

const ll INF = 1e18;

vector<vector<pll>> adj;
vector<ll> dijkstra(int src, int n)
{
    vector<ll> dist(2 * n, INF);                       // distances in the layered graph
    priority_queue<pll, vector<pll>, greater<pll>> pq; // min-heap
    pq.emplace(0, src);
    dist[src] = 0;

    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dist[u])
            continue;
        for (auto &[v, w] : adj[u])
        {
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                pq.emplace(dist[v], v);
            }
        }
    }

    return dist;
}

void solve()
{
    int n, m, u, v;
    ll w;
    cin >> n >> m;
    adj.resize(2 * n + 1);

    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);         // edge from u to v in original graph
        adj[v + n].emplace_back(u + n, w); // edge from v to u in reversed graph
    }

    for (int i = 1; i <= n; i++)
    {
        adj[i].emplace_back(i + n, 0); // zero-weight edge from original to reversed
    }

    vector<ll> dist = dijkstra(1, 2 * n); // start Dijkstra from (1, 0) in layered graph

    for (int k = 2; k <= n; k++)
    {
        // Find shortest path from (1,0) to (k,1) in the layered graph
        ll answer = dist[k + n]; // (k, 1) is represented as k + n
        if (answer == INF)
            cout << "-1 ";
        else
            cout << answer << " ";
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--)
        solve();
}
