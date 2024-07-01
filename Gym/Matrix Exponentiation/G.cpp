graph multiply(graph &a, graph &b)
{
    graph c(a.size(), vi(b[0].size(), 0));
    fr(i, a.size())
    {
        fr(j, b[0].size())
        {
            fr(k, a[0].size())
            {
                c[i][j] += (a[i][k] * b[k][j]) % N;
                c[i][j] %= N;
            }
        }
    }
    return c;
}
 
void solve()
{
    int n, k;
    read(n, k);
 
    vi a(n), c(n);
    read(a);
    read(c);
    int p, q, r;
    read(p, q, r);
 
    if (k < n)
    {
        cout << a[k] << endl;
        return;
    }
    // k -= (n - 1);
    int n_t = 0;
 
    for (int i = 0; i < n; i++)
    {
        n_t += (a[n - i - 1] * c[i]) * N;
    }
 
    graph g(n + 3, vi(n + 3, 0));
 
    for (int i = 0; i < n; i++)
    {
        g[0][i] = c[i];
    }
    g[0][n] = r;
    g[0][n + 1] = q;
    g[0][n + 2] = p;
    for (int i = 0; i < n - 1; i++)
    {
        g[i + 1][i] = 1;
    }
    g[n][n] = 1;
    g[n + 1][n + 1] = 1;
    g[n + 2][n + 2] = 1;
    g[n][n + 1] = 2;
    g[n][n + 2] = 1;
    g[n + 1][n + 2] = 1;
 
    graph res(n + 3, vi(1, 0));
    for (int i = 0; i < n; i++)
    {
        res[i][0] = a[n - i - 1];
    }
    res[n][0] = n * n;
    res[n + 1][0] = n;
    res[n + 2][0] = 1;
    k -= (n - 1);
    while (k > 0)
    {
        if (k % 2 == 1)
        {
            res = multiply(g, res);
        }
        g = multiply(g, g);
        k >>= 1;
    }
 
    cout << res[0][0];
}
