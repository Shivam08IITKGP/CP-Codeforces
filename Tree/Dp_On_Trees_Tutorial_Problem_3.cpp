// Finding number of subtrees containing <= K nodes
// This will contains also those subtrees which are not 
// assuming node 1 is the root
void solve()
{
    int n, k;
    cin >> n >> k;

    graph g(n);
    fr(i, n - 1)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].pb(v);
        g[v].pb(u);
    }

    graph f(n, vi(k + 1, 0));
    function<void(int, int)> dfs = [&](int u, int p)
    {
        f[u][1] = 1;
        vi dp(k + 1, 0);

        for (auto &child : g[u])
        {
            if (child == p)
                continue;
            dfs(child, u);

            vi new_dp(k + 1, 0);
            fr(i, k + 1)
            {
                fr(j, k - i + 1)
                {
                    new_dp[i + j] += f[u][i] * dp[j];
                }
            }
            dp = new_dp;
        }
        f[u] = dp;
    };

    dfs(0, -1);

    int ans = 0;
    fr(i, k + 1)
    {
        fr(j, n)
        {
            ans += f[j][i];
        }
    }
    cout << ans << endl;
}
