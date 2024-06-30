void solve()
{
    int n;
    cin >> n;
    map<int, int> freq;
    fr(i, n)
    {
        int x;
        cin >> x;
        freq[x]++;
    }
    vi a;
    for (auto i : freq)
    {
        a.pb(i.S);
    }
    int m = a.size();
    vi dp(2 * n + 1, 0);
    for (int i = 1; i < m; i++)
    {
        int ctr = (i - a[i]) + 1;
        for (int j = ctr - 1; j >= 0; j--)
        {
            remax(dp[j + a[i] + 1], dp[j] + 1);
        }
    }
    cout<<m-*max_element(all(dp))<<endl;
}
