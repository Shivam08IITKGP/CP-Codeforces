bool check(int num)
{
    while (num > 0)
    {
        if (num % 10 == 7 or num % 10 == 4)
        {
            num /= 10;
        }
        else
        {
            return false;
        }
    }
    return true;
}

void solve()
{
    int n;
    cin >> n;
    wgraph g(n);
    fr(i, n - 1)
    {
        int u, v, w;
        cin >> u >> v >> w;
        bool res = check(w);
        u--;
        v--;
        g[u].pb(MP(v, res));
        g[v].pb(MP(u, res));
    }

    vi indp(n, 0), outdp(n, 0), size(n, 1);

    /*
    -> C[u] will track the size of the subtree rooted at u when we root the tree at node 0.
    -> F[u] will count, among those C[u] descendants, how many have at least one lucky edge
    on the path down from u.
    -> outdp[u] will count, among the other nodes (not in u’s subtree), how many have
     at least one lucky edge on the path up/out from u.
    */

    function<void(int, int)> dfs1 = [&](int u, int p)
    {
        for (auto &it : g[u])
        {
            if (it.F == p)
                continue;
            dfs1(it.F, u);
            if (it.S)
            {
                indp[u] += size[it.F]; // (max(size[it.F], indp[it.F]) = size[it.F])
            }
            else
            {
                indp[u] += indp[it.F];
            }
            size[u] += size[it.F];
        }
    };

    function<void(int, int)> dfs2 = [&](int u, int p)
    {
        for (auto &it : g[u])
        {
            if (it.F == p)
                continue;

            if (it.S)
            {
                outdp[it.F] = n - size[it.F];
            }
            else
            {
                outdp[it.F] = outdp[u] + (indp[u] - indp[it.F]);
                // indp[u] - indp[it.F] gives the children of u that are not in the subtree of it.F
            }
            dfs2(it.F, u);
        }
    };

    dfs1(0, -1);
    dfs2(0, -1);

    int ans = 0;
    fr(i, n)
    {
        ans += indp[i] * (indp[i] - 1) + outdp[i] * (outdp[i] - 1) + 2 * indp[i] * outdp[i];
    }
    cout << ans << endl;
}
