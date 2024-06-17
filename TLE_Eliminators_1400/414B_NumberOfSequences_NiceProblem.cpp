const int MAXN = 2000;

void solve()
{
    int n, k;
    cin >> n >> k;

    graph dp(MAXN + 1, vi(MAXN + 1, 0));

    dp[0][1] = 1;
    for (int l = 1; l <= k; l++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = i; j <= n; j += i)
            {
                dp[l][j] += (dp[l - 1][i]);
                dp[l][j] %= N;
            }
        }
    }
    int ans = 0;
    rep(i, 1, n)
    {
        ans += dp[k][i];
        ans %= N;
    }
    cout << ans << endl;
}
