void solve()
{
    int n, m;
    read(n, m);
    graph g(n);
    fr(i, n - 1)
    {
        int u, v;
        read(u, v);
        u--, v--;
        g[u].pb(v);
        g[v].pb(u);
    }

    int k, x;
    read(k, x);

    vector<graph> dp(n, graph(3, vi(x + 1, 0)));
    graph a(3, vi(x + 1, 0)), b(3, vi(x + 1, 0));

    function<void(int, int)> dfs = [&](int u, int p)
    {
        bool leaf = true;
        int temp;
        for (auto child : g[u])
        {
            if (child == p)
                continue;
            leaf = false;
            dfs(child, u);
        }

        if (leaf)
        {
            dp[u][0][0] = k - 1;
            dp[u][1][1] = 1;
            dp[u][2][0] = m - k;
            return;
        }

        fr(i, 3)
        {
            fr(j, x + 1)
            {
                a[i][j] = 0;
                b[i][j] = 0;
            }
        }

        fr(i, 3)
        {
            a[i][0] = 1;
        }

        for (auto child : g[u])
        {
            if (child == p)
                continue;
            fr(i, 3)
            {
                fr(l, x + 1)
                {
                    fr(r, x + 1)
                    {
                        if (l + r > x)
                            continue;

                        if (i == 0)
                        {
                            temp = (dp[child][0][r] + dp[child][1][r] + dp[child][2][r]) % N;
                            // any child
                            b[i][l + r] = (b[i][l + r] + (a[i][l] * temp) % N) % N;
                            /*
a[i][j]: DP result for current subtree before adding next child
b[i][j]: Temporary holder for the result after adding this child

For each state:
State 0 (type < k): Can combine with any child state
State 1 (type == k): Can combine only with child of state 0 (since neighbors of type k must be < k)
State 2 (type > k): Can combine with children that are state 0 or 2 (but not 1)

Example:
Suppose:
You are at node cur with 3 children: C1, C2, C3.
You are processing them one-by-one.

After processing C1:
You store merged DP results into a[j][l].

While processing C2:
You combine:
All existing a[j][l] (ways of assigning vaults with l type-k so far), and
All dp[C2][*][r] (ways of assigning vaults in C2 with r type-k),
For all values of l and r where l + r <= x.

And you update:
b[j][l + r] += a[j][l] * dp[C2][...][r];

After that, set a = b, and repeat for C3, and so on.
                            */
                        }
                        else if (i == 1)
                        {
                            temp = (dp[child][0][r]) % N;
                            // only child having the security less than the highest security
                            b[i][l + r] = (b[i][l + r] + (a[i][l] * temp) % N) % N;
                        }
                        else
                        {
                            temp = (dp[child][0][r] + dp[child][2][r]) % N;
                            // only the child having greater(2) or lesser security(0) , not highest security(1)
                            b[i][l + r] = (b[i][l + r] + (a[i][l] * temp) % N) % N;
                        }
                    }
                }
            }
            fr(i, 3)
            {
                fr(j, x + 1)
                {
                    a[i][j] = b[i][j];
                    b[i][j] = 0;
                }
            }
        }
        fr(i, x + 1)
        {
            dp[u][0][i] = (1LL * a[0][i] * (k - 1)) % N;
            if (i > 0)
                dp[u][1][i] = a[1][i - 1];
            dp[u][2][i] = (1LL * a[2][i] * (m - k)) % N;
        }
    };

    dfs(0, -1);
    int ans = 0;
    fr(i, 3)
    {
        fr(j, x + 1)
        {
            ans = (ans + dp[0][i][j]) % N; // 0th vault is highest security vault
        }
    }
    cout << ans << endl;
}
