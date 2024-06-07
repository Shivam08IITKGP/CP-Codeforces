int n;
graph g(100005);
vi ans(100005), s(100005);

int dfs1(int node = 1, int par = -1)
{
    s[node] = 1;
    int points = 0;
    for (auto ch : g[node])
    {
        if (ch != par)
        {
            points += dfs1(ch, node);
            s[node] += s[ch];
        }
    }
    return points + s[node];
}

void dfs2(int node = 1, int par = -1)
{
    for (auto ch : g[node])
    {
        if (ch != par)
        {
            ans[ch] = ans[node] + n - 2 * s[ch];
            dfs2(ch,node);
        }
    }
}

void solve()
{
    cin >> n;
    rep(i, 0, n - 2)
    {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }

    ans[1] = dfs1();
    dfs2();
    cout<<*max_element(ans.begin()+1, ans.begin()+n+1)<<endl;
}
