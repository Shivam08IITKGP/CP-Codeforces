void solve()
{
    int n;
    cin >> n;
    vi a(n);
    read(a);
    int ans = a[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        ans = max(ans + 1, a[i]);
    }
    cout << ans << endl;
}
