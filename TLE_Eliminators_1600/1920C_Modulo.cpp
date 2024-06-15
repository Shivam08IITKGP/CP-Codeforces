void solve()
{
    int n;
    cin >> n;
    vi a(n);
    read(a);
    // int ans = 1;

    int gcd_ = a[0];
    for (int i = 1; i < n; i++)
    {
        gcd_ = __gcd(gcd_, a[i]);
    }

    vi fact;
    fact.pb(1);
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            fact.pb(i);
            if (i != n / i)
            {
                fact.pb(n / i);
            }
        }
    }
    if (n != 1)
        fact.pb(n);
    if (count(all(a), 1) == n or gcd_ > 1)
    {
        cout << fact.size() << endl;
        return;
    }
    // cout<<endl;
    fact.pop_back();

    int ans = 0;
    // cout << fact << endl;
    for (auto f : fact)
    {
        int m = abs(a[0] - a[f]);
        for (int i = 1; i < n - f; i++)
        {
            if (a[i] == a[i + f])
            {
                continue;
            }
            else
            {
                m = __gcd(m, abs(a[i + f] - a[i]));
            }
        }
        if (m > 1 or m == 0)
        {
            ans++;
        }
    }
    cout << ans + 1 << endl;
}
