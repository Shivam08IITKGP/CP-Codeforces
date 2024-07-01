void solve()
{
    int n;
    cin >> n;
 
    if (n == 0)
    {
        cout << 0;
        return;
    }
    if (n == 1)
    {
        cout << 1;
        return;
    }
    graph g{{1, 1}, {1, 0}};
    function<graph(graph, graph)> multiply = [&](graph a, graph b) -> graph
    {
        graph c(2, vi(2, 0));
        fr(i, 2)
        {
            fr(j, 2)
            {
                fr(k, 2)
                {
                    c[i][j] += (a[i][k] * b[k][j]) % N;
                    c[i][j] %= N;
                }
            }
        }
        return c;
    };
 
    function<graph(graph, int)> power = [&](graph a, int n) -> graph
    {
        graph res{{1}, {0}};
        while (n > 0)
        {
            if (n % 2 == 1)
            {
                res = multiply(g, res);
            }
            g = multiply(g, g);
            n >>= 1;
        }
        return res;
    };
 
    graph ans(power(g, n - 1));
    cout << ans[0][0];
}
