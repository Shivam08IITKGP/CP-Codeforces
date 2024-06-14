void solve()
{
    int n;
    cin >> n;
    vii a(n + 1);
    rep(i, 1, n)
    {
        cin >> a[i].F >> a[i].S;
    }
    vi index(n + 1);
    iota(all(index), 0);

    sort(all(index), [&a](int i, int j)
         {
        if (a[i].F == a[j].F) return a[i].S > a[j].S;
        return a[i].F < a[j].F; });
    sort(all(a), [&](ii a, ii b)
         {
        if (a.F == b.F) return a.S > b.S;
        return a.F < b.F; });

    set<int> sp;
    for (int i = 1; i <= n; i++)
    {
        while (!sp.empty() && a[*sp.begin()].S < a[i].F)
        {
            sp.erase(sp.begin());
        }
        if (!sp.empty())
        {
            auto it = sp.rbegin();
            if (a[*it].S >= a[i].S)
            {
                cout << index[i] << " " << index[*it] << endl;
                return;
            }
        }

        sp.insert(i);
    }

    cout << "-1 -1" << endl;
}
