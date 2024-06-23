vi d;
 
void solve()
{
    int n, k;
    read(n, k);
    vi b(n), c(n);
    read(b);
    read(c);
    int sum = 0;
 
    for (auto x : b)
    {
        sum += d[x];
    }
    remin(k, sum);
    vi dp(k + 1, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = k - d[b[i]]; j >= 0; j--)
        {
            remax(dp[j + d[b[i]]], dp[j] + c[i]);
        }
    }
    cout << *max_element(all(dp)) << endl;
}
 
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    const int N = 1001;
    d.assign(N, N);
    d[1] = 0;
    for (int i = 1; i < N; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            int x = i + i / j;
            if (x < N)
                d[x] = min(d[x], d[i] + 1);
        }
    }
 
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
