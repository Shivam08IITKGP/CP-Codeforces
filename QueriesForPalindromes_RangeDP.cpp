void solve()
{
    string s;
    cin >> s;
    n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    vector<vector<bool>> isPal(n + 1, vector<bool>(n + 1, 0));
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = 1;
        isPal[i][i] = 1;
        isPal[i + 1][i] = 1;
        //This line is for the case when len=2
        //This is because if len=2, start+1>start+len-2 and it will return false
    }
    for (int len = 2; len <= n; len++)
    {
        for (int start = 0; start <= n - len; start++)
        {
            isPal[start][start + len - 1] = isPal[start + 1][start + len - 2] & (s[start] == s[start + len - 1]);
            dp[start][start + len - 1] = dp[start + 1][start + len - 1] + dp[start][start + len - 2] - dp[start + 1][start + len - 2] + isPal[start][start + len - 1];
        }
    }
    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        l--, r--;
        cout << dp[l][r] << endl;
    }
}
