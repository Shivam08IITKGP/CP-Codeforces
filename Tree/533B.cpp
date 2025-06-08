void solve()
{
    int n;
    cin >> n;

    graph g(n);
    vi a(n);
    fr(i, n)
    {
        int p;
        cin >> p >> a[i];

        if (p != -1)
        {
            g[p - 1].pb(i);
        }
    }
    // Goal: select a subset of nodes such that the sum of their values is maximized
    // and the number of nodes in the subtree of any node in the subset is even (except itself)

    // dp[u][0] = max sum with u not selected
    // dp[u][1] = max sum with u selected and number of nodes in subset chosen from subtree of u is even

    graph dp(n, vi(2, 0));
    function<void(int)> dfs = [&](int u)
    {
        if (g[u].empty())
        {
            dp[u][0] = 0;
            dp[u][1] = a[u];
            return;
        }

        vi penalty;
        int tmp1 = 0, tmp2 = 0;
        for (auto child : g[u])
        {
            dfs(child);
            tmp1 += dp[child][0];
            penalty.pb(dp[child][0] - dp[child][1]);
        }
        /*
        tmp1 = sum of dp[child][0] = total value when none of the children are selected.
        vec[i] = dp[child][0] - dp[child][1]: penalty if we decide to select this child.
        Why? Selecting a child gives dp[child][1], not selecting gives dp[child][0].
        So the cost of selecting is dp[child][0] - dp[child][1].
        */

        sort(all(penalty));
        /*
        We want to include children in pairs (to satisfy the even-count constraint),
        and the cheapest children to switch from unselected → selected are at the front.
        */

        tmp2 = tmp1;
        tmp2 -= penalty[0];
        dp[u][0] = tmp1;
        dp[u][1] = tmp2;

        /*
dp[v][0] = tmp1: If you select no child, your subtree has 0 selected children → even ⇒ valid.
dp[v][1] = tmp2: If you select v and one child, your selected subordinate count = 1 → odd.
        */

        for (int i = 0; i + 1 < sz(penalty); i += 2)
        {
            tmp1 -= (penalty[i] + penalty[i + 1]);
            dp[u][0] = max(tmp1, dp[u][0]);
            /*
Try removing pairs of values (i.e., selecting 2, 4, 6… children).
Each pair adds 2 selected subordinates — still even ⇒ valid.
            */
        }
        for (int i = 1; i + 1 < sz(penalty); i += 2)
        {
            tmp2 -= (penalty[i] + penalty[i + 1]);
            dp[u][1] = max(tmp2, dp[u][1]);
            
        }
        remax(dp[u][1], dp[u][0] + a[u]);
    };

    dfs(0);

    cout << max(dp[0][0], dp[0][1]) << endl;
}
