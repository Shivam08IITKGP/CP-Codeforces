void solve()
{
    int n;
    cin >> n;
    vii p;
    fr(i, n)
    {
        int l, r;
        cin >> l >> r;
        p.pb({l, 1});
        p.pb({r + 1, -1});

    }
    int cnt = 0;
    sort(all(p));
    fr(i,2*n)
    {
        cnt+= p[i].S;
        if(cnt>=3)
        {
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
    return;
}
