void solve()
{
    vi v;
    int n, m, k;
    cin >> n >> m >> k;
    vi a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 2; i <= n; i++)
    {
        v.push_back(a[i] - a[i - 1] - 1);
    }
    sort(rall(v));
    int ans = a[n] - a[1] + 1;
    for (int i = 0; i < k - 1; i++)
    {
        ans -= v[i];
    }
    cout << ans << endl;
}
