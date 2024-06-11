void solve()
{
    int n;
    cin >> n;
    vi a(n + 1); // +1 to make it 1-based index
    rep(i, 1, n)
    {
        cin >> a[i];
    }

    vector<bool> s(n + 1);
    rep(i, 1, n)
    {
        s[i] = (a[i] < i);
    }

    int ans = 0;
    vector<int> v;
    rep(i, 1, n)
    {
        if (s[i])
        {
            ans += lower_bound(all(v), a[i]) - v.begin();
            v.pb(i);
        }
    }

    cout << ans << endl;
}
