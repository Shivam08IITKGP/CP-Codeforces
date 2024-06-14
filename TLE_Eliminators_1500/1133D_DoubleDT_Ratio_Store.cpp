void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    int mx = 0;
    int cnt = 0;
    map<pair<int, int>, int> m;

    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0 && b[i] == 0)
        {
            cnt++;
            continue;
        }
        if (a[i] == 0)
        {
            continue;
        }
        int g = __gcd(a[i], b[i]);
        pair<int, int> slope = {b[i] / g, a[i] / g};
        if (slope.first < 0)
        {
            slope.first = -slope.first;
            slope.second = -slope.second;
        }
        m[slope]++;
        mx = max(mx, m[slope]);
    }

    cout << mx + cnt << endl;
}
