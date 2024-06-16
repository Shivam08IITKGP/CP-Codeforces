void solve()
{
    int n;
    cin >> n;
    vi a(n);
    read(a);
    int cnt = count(all(a), 0);
    if (cnt == n)
    {
        cout << "No\n";
        return;
    }
    vi b(cnt, 0);
    vi pos, neg;
    fr(i, n)
    {
        if (a[i] > 0)
        {
            pos.pb(a[i]);
        }
        else if (a[i] < 0)
        {
            neg.pb(a[i]);
        }
    }
    sort(all(pos), greater<int>());
    sort(all(neg));
    int sum = 0;
    int i = 0, j = 0;
    while (i < sz(pos) and j < sz(neg))
    {
        if (sum > 0)
        {
            sum += neg[j];
            b.pb(neg[j]);
            j++;
        }
        else
        {
            sum += pos[i];
            b.pb(pos[i]);
            i++;
        }
    }
    while (i < sz(pos))
    {
        sum += pos[i];
        b.pb(pos[i]);
        i++;
    }
    while (j < sz(neg))
    {
        sum += neg[j];
        b.pb(neg[j]);
        j++;
    }
    cout << "Yes\n";
    cout << b << endl;
}
