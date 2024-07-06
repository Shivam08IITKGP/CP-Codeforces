void solve()
{
    int n;
    cin >> n;
    // vi a(n)

    graph g(n + 1);

    fr(i, n - 1)
    {
        int x;
        cin >> x;
        g[x].pb(i + 2);
    }

    vi cnt;
    function<int(int)> dfs = [&](int node) -> int
    {
        int ct = 0;
        for (auto child : g[node])
        {
            ct += dfs(child);
        }
        if (ct == 0)
        {
            ct++;
        }
        cnt.pb(ct);
        return ct;
    };

    dfs(1);
    sort(all(cnt));
    cout << cnt << endl;
}
