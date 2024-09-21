void solve()
{
    int n;
    cin >> n;
    vi a(n);
    read(a);

    int mn = INF;
    int mx = 0;

    int s = 0;
    // Selecting the min segment
    for (int i = 0; i < n; i++)
    {
        s += a[i];
        mn = min(mn, s / (i + 1));
    }
    s = 0;
    // Selecting the max segment
    for (int i = n - 1; i >= 0; i--)
    {
        s += a[i];
        mx = max(mx, (s + n - i - 1) / (n - i));
    }
    cout << mx - mn << endl;
}
