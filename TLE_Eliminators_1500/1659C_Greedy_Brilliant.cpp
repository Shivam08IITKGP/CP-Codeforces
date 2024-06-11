void solve()
{
    int n, a, b;
    cin >> n >> a >> b;
    vi x(n);
    vi p(n + 1, 0);
    read(x);
    p[0] = 0;
    rep(i, 1, n)
    {
        p[i] = p[i - 1] + x[i - 1];
    }
    int ans = b * (p[n]);
    for (int i = 0; i < n; i++)
    {
        // for i= 0 a*x[0]+ b*(xn-x0 + xn-1-x0+ .....x1-x0+x0-0)
        // That is a*x[0]+ b*(p[n]- (n-1)x0)
        remin(ans, a * x[i] + b * (p[n] - p[i] - (n - i - 1) * x[i]));
    }
    cout << ans << endl;
}
