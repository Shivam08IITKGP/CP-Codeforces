void solve()
{
    int n;
    cin >> n;
    vi a(n + 1);
    read1(a);
    vi dp(n + 1);
    dp[0] = 1;
    // Always marking 1 where there is a possible sequence that is following the constraints
    for (int i = 1; i <= n; i++)
    {
        if ((i + a[i]) <= n and dp[i - 1])
            dp[i + a[i]] = 1;
        // a[i] is the length of the upcoming sequence
        if ((i - a[i]) >= 1 and dp[i - a[i] - 1])
            dp[i] = 1;
        // a[i] is the length of the back sequence
    }
    cout << (dp[n] ? "Yes" : "No") << endl;
}
