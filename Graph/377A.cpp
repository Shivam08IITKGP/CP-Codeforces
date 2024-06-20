// ON each bfs/dfs for problem C, you should check everytime is it blocking other free cells paths or not.
void solve()
{
    int n, m, k;
    read(n, m, k);
    vector<string> g(n);
    read(g);

    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};
  
    function<bool(ii)> check = [&](ii node) -> bool
    {
        return node.F >= 0 and node.S >= 0 and node.F < n and node.S < m and g[node.F][node.S] == '.';
    };

    vii top_sort;
    graph vis(n, vi(m, 0));

    function<void(ii)> dfs = [&](ii node) -> void
    {
        for (int i = 0; i < 4; i++)
        {
            int xx = node.F + dx[i];
            int yy = node.S + dy[i];
            if (check({xx, yy}) and vis[xx][yy] == 0)
            {
                vis[xx][yy] = 1;
                dfs({xx, yy});
            }
        }
        top_sort.pb(node);
    };

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            if (check({i, j}))
            {
                vis[i][j] = 1;
                dfs({i, j});
                i = n;
                break;
            }
        }
    }
    for (int i = 0; i < k; i++)
    {
        g[top_sort[i].F][top_sort[i].S] = 'X';
    }
    fr(i, n)
    {
        cout << g[i] << endl;
    }
}
