void solve()
{
    int n, m;
    read(n, m);
    graph g(n + 1);
    rep(i, 1, n - 1)
    {
        int u, v;
        read(u, v);
        g[u].pb(v);
        g[v].pb(u);
    }
    vi tin(n + 1, 0), tout(n + 1, 0);
    int T = 0;
    vi p(n + 1);
    vi depth(n + 1, 0);
    function<void(int, int)> dfs = [&](int node, int par) -> void
    {
        tin[node] = T++;
        p[node] = par;

        for (auto chi : g[node])
        {
            if (chi == par)
                continue;
            depth[chi] = 1 + depth[node];
            dfs(chi, node);
        }
        tout[node] = T++;
    };
    // function<int(int, int)> lca = [&](int x, int y) -> int
    // {
    //     if (depth[x] > depth[y])
    //     {
    //         swap(x, y);
    //     }
    //     for (int i = 29; i >= 0; i--)
    //     {
    //         if ((depth[x] - depth[y]) & (1 << i))
    //         {
    //             x = p[x][i];
    //         }
    //     }

    //     for (int i = 29; i >= 0; i--)
    //     {
    //         if (p[x][i] != p[y][i])
    //         {
    //             x = p[x][i];
    //             y = p[y][i];
    //         }
    //     }
    //     return p[x][0];
    // };

    function<bool(int, int)> isAncestor = [&](int node, int p) -> bool
    {
        return tin[p] <= tin[node] and tout[p] >= tout[node];
    };

    dfs(1, 0);
    while (m--)
    {
        int k;
        cin >> k;
        vi path(k);
        read(path);

        int u = path[0];
        for (auto c : path)
        {
            if (depth[c] > depth[u])
            {
                u = c;
            }
        }

        for (auto &c : path)
        {
            if (p[c] != 0)
            {
                c = p[c];
            }
        }
        bool f= true;

        for (auto c : path)
        {
            if (!isAncestor(u, c))
            {
                f= false;
            }
        }
        if(!f)
        {
            cout<<"NO\n";
            continue;
        }
        else
        {
            cout<<"YES\n";
        }
    }
}
