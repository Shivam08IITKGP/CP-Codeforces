
void dfs(int node, int par, vi &size, graph &adj, vi &dp)
{
    size[node] = 1;
    int totaldpchild = 0;
    for (auto child : adj[node])
    {
        if (child != par)
        {
            dfs(child, node, size, adj, dp);
            size[node] += size[child];
            totaldpchild += dp[child];
        }
    }
    for (auto child : adj[node])
    {
        if (child != par)
        {
            dp[node] = max(dp[node], totaldpchild - dp[child] + size[child] - 1);
        }
    }
}
