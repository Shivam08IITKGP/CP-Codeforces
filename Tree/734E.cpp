void solve()
{
    int n;
    cin >> n;
    vi a(n);
    read(a);
    graph g(n);
    fr(i, n - 1)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].pb(v);
        g[v].pb(u);
    }

    // My strategy would be to count the number of counters of white and black
    // and return minimum of them
    // This is wrong strategy

    vi visited(n, 0);

    // int white = 0, black = 0;
    // function<void(int, int)> dfs = [&](int node, int color)
    // {
    //     visited[node] = 1;
    //     for (auto child : g[node])
    //     {
    //         if (visited[child])
    //         {
    //             continue;
    //         }
    //         else if (a[child] == color)
    //         {
    //             dfs(child, color);
    //         }
    //     }
    // };

    // for (int i = 0; i < n; i++)
    // {
    //     if (visited[i])
    //         continue;
    //     if (a[i] == 0)
    //     {
    //         white++;
    //         dfs(i, 0);
    //     }
    //     else
    //     {
    //         black++;
    //         dfs(i, 1);
    //     }
    // }
    // cout << min(abs(white - black), min(white, black)) << endl;

    vi dp(n);
    vi comp(n, 0);
    function<void(int, int, int)> dfs = [&](int node, int color, int component)
    {
        visited[node] = 1;
        comp[node] = component;
        for (auto &child : g[node])
        {
            if (!visited[child] and a[child] == color)
                dfs(child, color, component);
        }
    };

    int compon = 0;
    fr(i, n)
    {
        if (!visited[i])
        {
            dfs(i, a[i], compon);
            compon++;
        }
    }
    graph compressed_Graph(compon);

    int ans = 0;

    fr(i, n)
    {
        for (auto &child : g[i])
        {
            if (comp[i] != comp[child])
            {
                compressed_Graph[comp[i]].pb(comp[child]);
                // note: we are not adding reverse edge bcz when we come to the child node
                // in the fr(i, n), then we will add the edge from child to parent
                // hence we are not adding reverse edge
            }
        }
    }

    // This function now finds the diameter of the compressed graph
    function<void(int, int)> dfs2 = [&](int node, int parent)
    {
        int max_1 = 0, max_2 = 0;
        for (auto &child : compressed_Graph[node])
        {
            if (child == parent)
                continue;

            dfs2(child, node);

            int val = 1 + dp[child];
            remax(max_2, val);
            if (max_2 > max_1)
            {
                swap(max_1, max_2);
            }
        }
        dp[node] = max_1;
        remax(ans, max_1 + max_2);
    };

    dfs2(0, -1);

    cout << (ans + 1) / 2 << endl;
}
