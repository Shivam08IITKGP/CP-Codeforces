void solve()
{
    int n, k;
    cin >> n >> k;
    vi a(n);
    read(a);
    sort(all(a));
    vi cnt(n, 0);
    for (int i = 0; i < n; i++)
    {
        while (i + cnt[i] < n and a[i + cnt[i]] - a[i] <= 5)
        {
            cnt[i]++;
        }
    }
// o (n2) approach to calculate the cnt    
    graph dp(n + 1, vi(k + 1, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            // This is for including the i-1 th element and ith element
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
            if (j < k)
            {
                remax(dp[i + cnt[i]][j + 1], dp[i][j] + cnt[i]);
                //THis is for making all the numbers in seperate groups from i to i+cnt[i]
            }
        }
    }

// O(n*k) to calculate all the dp values
    cout << dp[n][k] << endl;
}
