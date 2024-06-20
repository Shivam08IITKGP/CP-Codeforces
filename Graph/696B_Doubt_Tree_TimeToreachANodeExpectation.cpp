void solve()
{
    int n;
    cin >> n;
    graph g(n + 1);
    rep(i, 1, n - 1)
    {
        int x;
        cin >> x;
        g[x].pb(i + 1);
    }
    vi siz(n + 1, 0), depth(n + 1, 0);

    function<void(int, int)> dfs = [&](int node, int par) -> void
    {
        siz[node] = 1;
        for (auto chi : g[node])
        {
            if (chi != par)
            {
                depth[chi] = 1 + depth[node];
                dfs(chi, node);
                siz[node] += siz[chi];
            }
        }
    };
    depth[1] = 0;
    dfs(1, 0);
    rep(i, 1, n)
    {
        long double ans = (n - siz[i] - depth[i]) * 1.0 + (1 + depth[i]) * 2.0;
        ans /= 2.0;
        cout << ans << " ";
    }
    cout << endl;
}
