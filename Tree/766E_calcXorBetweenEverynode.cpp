graph g(100005), child(100005);
vi a(100005);
graph arr(100005, vi(32, 0));
int dp[100005][32][2];
vi ans(100005, 0);

void dfs(int node, int par)
{
    for (auto chi : g[node])
    {
        if (chi != par)
        {
            child[node].pb(chi);
            dfs(chi, node);
        }
    }
}

void dpsolve(int node)
{
    if (child[node].size() == 0)
        return;
    for (auto chi : child[node])
    {
        dpsolve(chi);
        rep(i, 0, 31)
        {
            // ans[node] means all the paths that include the node and in the subtree
            // or paths where node is the lca
            // so considering every node as lca we will add up taking every node lca
            // Will there be any paths that are not ccounted in the lca of every node

            // are these the lcas?
            // Yes as we are adding themfor every child
            ans[node] += (dp[node][i][1] * dp[chi][i][0] + dp[node][i][0] * dp[chi][i][1]) * (1LL << i);
            if (arr[node][i])
            {
                dp[node][i][1] += dp[chi][i][0];
                dp[node][i][0] += dp[chi][i][1];
            }
            else
            {
                dp[node][i][1] += dp[chi][i][1];
                dp[node][i][0] += dp[chi][i][0];
            }
        }
    }
}

void solve()
{
    int n;
    read(n);
    rep(i, 1, n)
    {
        cin >> a[i];
    }
    rep(i, 1, n - 1)
    {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    memset(dp, 0, sizeof(dp));

    rep(i, 0, 31)
    {
        rep(j, 1, n)
        {
            if ((a[j] >> i) & 1)
            {
                arr[j][i] = 1;
                dp[j][i][1] = 1;
                ans[j] += 1LL << i;
            }
            else
            {
                dp[j][i][0] = 1;
            }
        }
    }
    dfs(1, -1);
    dpsolve(1);
    cout << accumulate(ans.begin(), ans.begin() + n + 2, 0LL) << endl;
    // vi ans(32,0);
}

