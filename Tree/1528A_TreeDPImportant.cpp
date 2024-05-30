void dfs(int node, int par, graph &adj, vi &l, vi &r, graph &dp)
{
    for (auto child : adj[node])
    {
        if (child == par)
            continue;
        dfs(child, node, adj, l, r, dp);
        dp[node][0] += max(dp[child][0] + abs(l[child] - l[node]), dp[child][1] + abs(r[child] - l[node]));
        dp[node][1] += max(dp[child][0] + abs(l[child] - r[node]), dp[child][1] + abs(r[child] - r[node]));
    }
}

void solve()
{
    int n;
    cin >> n;
    vector<int> l(n + 1), r(n + 1);
    rep(i, 1, n)
    {
        cin >> l[i] >> r[i];
    }
    graph adj(n + 1);
    rep(i, 1, n - 1)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    graph dp(n + 1, vi(2, 0));
    dfs(1, -1, adj, l, r, dp);
    cout << max(dp[1][0], dp[1][1]) << endl;
}
