void solve()
{
    int n, k;
    cin >> n >> k;
    graph g(n + 1);

    // Reading edges
    vi cnt(n + 1, 0);
    for (int i = 0; i < 2 * k; i++)
    {
        int x;
        cin >> x;
        cnt[x]++;
    }
    for (int i = 1; i < n; ++i)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int ans = 0;

    // cnt[node] means the total number of universities in the subtree node
    // Every node from u to v (u is parent) can be either included
    // min(cnt[node] times(inside the subtree) or 2*k-cnt[node] times(outside the subtree))
    // Becuase you cant connect more than this pairs from this edge

    function<void(int, int)> dfs = [&](int node, int par)
    {
        for (auto chi : g[node])
        {
            if (chi != par)
            {
                dfs(chi, node);
                cnt[node] += cnt[chi];
            }
        }
        ans += min(cnt[node], 2 * k - cnt[node]);
    };


    dfs(1, -1);

    cout << ans << endl;
}
