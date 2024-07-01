void solve()
{
    int n;
    cin >> n;
    graph m(2, vi(2, 0));
    m[0][0] = 19;
    m[0][1] = 6;
    m[1][0] = 7;
    m[1][1] = 20;
 
    function<graph(graph, graph)> multiply = [&](graph a, graph b)
    {
        graph c(2, vi(2, 0));
        for (int i = 0; i < 2; ++i)
        {
            for (int j = 0; j < 2; ++j)
            {
                for (int k = 0; k < 2; ++k)
                {
                    c[i][j] += (a[i][k] * b[k][j]) % N;
                    c[i][j] %= N;
                }
            }
        }
        return c;
    };
 
    function<graph(graph, int)> power = [&](graph a, int n)
    {
        graph res{{1, 0}, {0, 1}};
        while (n > 0)
        {
            if (n & 1)
            {
                res = multiply(res, a);
            }
            a = multiply(a, a);
            n >>= 1;
        }
        return res;
    };
 
    graph ans = power(m, n);
    cout << ans[0][0] << endl;
}
