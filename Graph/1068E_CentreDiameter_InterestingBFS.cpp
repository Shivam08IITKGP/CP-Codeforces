void solve()
{
    int n, k;
    read(n, k);
    graph g(n + 1);
    vi deg(n + 1, 0);
    if (n == 1 and k == 1)
    {
        cn;
    }
    rep(i, 1, n - 1)
    {
        int u, v;
        read(u, v);
        g[u].pb(v);
        g[v].pb(u);
        deg[u]++;
        deg[v]++;
    }
    vi parent(n + 1, 0);
    vi depth(n + 1, 0);

    int v_max;
    int max_dep = 0;
    function<void(int, int)> dfs = [&](int node, int par) -> void
    {
        for (auto chi : g[node])
        {
            if (chi != par)
            {
                parent[chi] = node;
                depth[chi] = 1 + depth[node];
                if (max_dep < depth[chi])
                {
                    v_max = chi;
                    max_dep = depth[chi];
                }
                dfs(chi, node);
            }
        }
    };
    dfs(1, 0);
    fr(i, n + 1)
    {
        parent[i] = 0;
        depth[i] = 0;
    }
    max_dep = 0;
    int u_max = v_max;
    dfs(u_max, 0);

    if (depth[v_max] & 1)
    {
        cn;
    }
    int centre = v_max;
    for (int i = 0; i < depth[v_max] / 2; i++)
    {
        centre = parent[centre];
    }

    queue<int> q;
    q.push(centre);
    vi vis(n + 1, 0);
    vis[centre] = 1;
    if (deg[centre] < 3)
    {
        cn;
    }
    int tim = 0;
    while (!q.empty())
    {
        tim++;
        int siz = q.size();

        fr(i, siz)
        {
            int node = q.front();
            q.pop();

            for (auto neigh : g[node])
            {
                if (!vis[neigh])
                {
                    if (tim == k and deg[neigh] == 1)
                    {
                        continue;
                    }
                    else if (tim == k)
                    {
                        cn;
                    }
                    else if (deg[neigh] > 3)
                    {
                        vis[neigh] = 1;
                        q.push(neigh);
                    }
                    else
                    {
                        cn;
                    }
                }
            }
        }
    }
    cy;
