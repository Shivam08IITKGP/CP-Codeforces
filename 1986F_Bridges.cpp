// Note: tin[node] is not the size of the connected component
// We have to calculate the size of the component seperate DFS
vi DP, vis, low, tin;
set<pair<int, int>> bridges;
graph g;
int tim, ans;
int n;

void DFS1(int node, int par)
{
    low[node] = tin[node] = ++tim;
    for (auto ch : g[node])
    {
        if (ch == par)
            continue;
        if (!vis[ch])
        {
            vis[ch] = 1;
            DFS1(ch, node);

            low[node] = min(low[node], low[ch]);
            if (low[ch] > tin[node])
            {
                bridges.insert({node, ch});
            }
        }
        else
        {
            low[node] = min(low[node], tin[ch]);
        }
    }
}

void DFS2(int node, int par)
{
    vis[node] = 1;
    int s = 0;
    for (auto ch : g[node])
    {
        if (ch == par)
            continue;
        if (!vis[ch])
        {
            DFS2(ch, node);
            s += DP[ch];

            if (bridges.find({node, ch}) != bridges.end())
            {
                ans = min(ans, DP[ch] * (DP[ch] - 1) / 2 + (n - DP[ch]) * (n - DP[ch] - 1) / 2);
            }
        }
    }
    DP[node] = s + 1;
}

void solve()
{
    int m;
    cin >> n >> m;
    g.resize(n + 1);
    DP.assign(n + 1, 0);
    vis.assign(n + 1, 0);
    low.assign(n + 1, 0);
    tin.assign(n + 1, 0);
    ans2 = n * (n - 1) / 2;

    for (int i = 0; i <= n; i++)
    {
        g[i].clear();
    }

    bridges.clear();
    tim = 0;
    ans = n * (n - 1) / 2;
    fr(i, m)
    {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }

    DFS1(1, 0);
    for (int i = 1; i <= n; i++)
    {
        vis[i] = 0;
    }
    DFS2(1, 0);
    cout << ans << endl;
}
