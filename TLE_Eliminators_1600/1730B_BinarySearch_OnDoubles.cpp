const long double prec = 1e-6;

#define ld long double

void solve()
{
    int n;
    cin >> n;
    vector<ld> t(n), x(n);
    read(x);
    read(t);
    if (n == 1)
    {
        cout << x[0] << endl;
        return;
    }
    ld l = -1, r = 1e9;

    auto check = [&](ld T) -> bool
    {
        ld minRight = 1e9;
        ld maxLeft = -1;

        for (int i = 0; i < n; i++)
        {
            if (T < t[i])
            {
                return false;
            }
            // T>t[i]
            remin(minRight, x[i] + T - t[i]);
            remax(maxLeft, x[i] - T + t[i]);
        }
        return (maxLeft <= minRight);
    };

    // int ti;
    while (r - l > prec)
    {
        ld T = (l + r) / 2.0;
        if (check(T))
        {
            r = T;
        }
        else
        {
            l = T;
        }
    }

    ld minRight = 1e9, maxLeft = -1;
    for (int i = 0; i < n; i++)
    {
        remin(minRight, x[i] + r - t[i]);
        remax(maxLeft, x[i] - r + t[i]);
    }
    cout << maxLeft << endl;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    cout << setprecision(14);
    while (t--)
    {
        solve();
    }
}
