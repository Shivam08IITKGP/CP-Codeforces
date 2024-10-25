void solve()
{
    int n;
    cin >> n;
    vi a(n);
    read(a);
    fr(i, n)
    {
        a[i]--;
    }
    int ans = 0;
    vector<bool> ok(n, 0);

    fr(i, n)
    {
        if (!ok[i])
        {
            int len = 0;
            int x = i;
            while (!ok[x])
            {
                ok[x] = 1;
                x = a[x];
                len++;
            }
            ans += (len + 1) / 2 - 1;
        }
    }

    cout << ans << endl;
}
