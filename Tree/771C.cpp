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

    graph count_subtrees_with_depth(n, vi(k, 0));
    vi size_subtree(n, 1);
    int ans = 0;

    function<void(int, int, int)> dfs = [&](int u, int p, int depth)
    {
        count_subtrees_with_depth[u][depth % k]++;
        for (int v : g[u])
        {
            if (v == p)
                continue;
            dfs(v, u, 1 + depth);

            fr(i, k)
            {
                fr(j, k)
                {
                    int remainder = (i + j - 2 * depth + k) % k;
                    int need = (k - remainder) % k;

                    // this represents the extra jumps contributer not fullfilled by multiples of k
                    // these many nodes count[u][i]*count[v][j] are needing these extra jumps to reach each other
                    // Note this sum is not (i + j + need) *count[u][i] * count[v][j]
                    // Because we have split the summation into two parts
                    // 1) this part is the extra jumps 
                    // the below's below part is the part which is actual summation of distance between all pairs of nodes
                    
                    ans += need * count_subtrees_with_depth[u][i] * count_subtrees_with_depth[v][j];
                }
            }
            fr(i, k)
            {
                count_subtrees_with_depth[u][i] += count_subtrees_with_depth[v][i];
            }
            size_subtree[u] += size_subtree[v];
        }
        // this represents the summation of all pairs of nodes distance 
        ans += size_subtree[u] * (n - size_subtree[u]);
    };

    dfs(0, -1, 0);
    cout << ans / k << endl;
}
