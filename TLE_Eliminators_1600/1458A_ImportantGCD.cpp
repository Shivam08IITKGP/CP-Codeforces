void solve()
{
    int n, m;
    cin >> n >> m;
    vi a(n), b(m);
    read(a);
    read(b);
    int gcd = 0;
    for (int i = 1; i < n; i++)
    {
        gcd = __gcd(gcd, abs(a[i] - a[0]));
    }
    for (int i = 0; i < m; i++)
    {
        cout << __gcd(a[0] + b[i], gcd) << " ";
    }
    cout << endl;
}
