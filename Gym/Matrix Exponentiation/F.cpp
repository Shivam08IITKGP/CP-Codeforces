graph multiply(graph &a, graph &b)
{
    graph c(a.size(), vi(b[0].size(), INF));
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (a[i][k] != INF and b[k][j] != INF)
                    c[i][j] = min(c[i][j], a[i][k] + b[k][j]);
            }
        }
    }
    return c;
}
 
void solve()
{
    int n, m, k;
    read(n, m, k);
 
    graph g(n + 1, vi(n + 1, INF));
 
    // rep(i, 1, n)
    // {
    //     g[i][i] = 0;
    // }
 
    fr(i, m)
    {
        int u, v, w;
        read(u, v, w);
        remin(g[u][v], w);
    }
 
    graph res(g);
 
    k--;
 
    while (k > 0)
    {
        if (k % 2 == 1)
        {
            res = multiply(res, g);
        }
        g = multiply(g, g);
        k /= 2;
    }
    // for(int i=0;i<=n;i++)
    // {
    //     cout<<res[i]<<endl;
    // }
 
    int ans = INF;
 
    rep(i, 1, n)
    {
        rep(j, 1, n)
        {
            remin(ans, res[i][j]);
        }
    }
 
    if (ans != INF)
        cout << ans << endl;
    else
    {
        cout << "IMPOSSIBLE\n";
    }
}
