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
    int n, m, k;
    read(n, m, k);
 
    graph g(n + 1, vi(n + 1, 0));
 
    fr(i, m)
    {
        int u, v;
        read(u, v);
        g[u][v]++;
    }
 
    graph res(g);
 
    k--;
    while (k > 0)
    {
        if (k % 2 == 1)
        {
            res = multiply(g, res);
        }
        g = multiply(g, g);
        k /= 2;
    }
    int ans = 0;
    fr(i, n + 1)
    {
        fr(j, n + 1)
        {
            ans += res[i][j];
            ans %= N;
        }
    }
    cout << ans << endl;
}
