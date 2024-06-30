void solve()
{
    int n;
    cin >> n;
    vi a(n + 1);
    read1(a);
    graph g(n + 1);
    vi d(n + 1);
    d[1] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int x;
        cin >> x;
        g[x].pb(i + 2);
        d[i + 2] = d[x] + 1;
    }

    vi b(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        if (g[i].empty())
        {
            b[i] = INF;
        }
        else
        {
            b[i] = -a[i];
            for (auto chi : g[i])
            {
                b[i] += a[chi];
            }
        }
    }
    int ans = 0;
    for (int v = n; v >= 0; v--)
    {
        queue<int> q;
        q.push(v);
        while (!q.empty())
        {
            int i = q.front();
            q.pop();

            for (auto u : g[i])
            {
                int delta = min(-b[v], b[u]);
                if (delta > 0)
                {
                    b[v] += delta;
                    b[u] -= delta;
                    ans += delta * (d[u] - d[v]);
                }
                q.push(u);
            }
        }
    }
    cout << ans << endl;
}
