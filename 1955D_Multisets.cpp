void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vi a(n), b(m);
    fr(i, n)
    {
        cin >> a[i];
    }
    fr(i, m)
    {
        cin >> b[i];
    }

    multiset<int> B, Done, Extra;

    fr(i, m)
    {
        B.insert(b[i]);
    }
    fr(i, m)
    {
        if (B.find(a[i]) != B.end())
        {
            B.erase(B.find(a[i]));
            Done.insert(a[i]);
        }
        else 
        {
            Extra.insert(a[i]);        
        }
    }
    int ans = (Done.size() >= k);
    for (int r = m; r < n; ++r)
    {
        int old = a[r - m];
        if(Extra.find(old)!= Extra.end())
        {
            Extra.erase(Extra.find(old));
        }
          // Extra multiset's significance is only because of the below word 'else if'
          // If we were not using Extra, then Done.find(old) != Done.end() might have removed it
          // As the arrays can store duplicates also, we have to deal with the duplicates by using Extra multiset
        else if (Done.find(old) != Done.end())
        {
            Done.erase(Done.find(old));
            B.insert(old);
        }
        if (B.find(a[r]) != B.end())
        {
            B.erase(B.find(a[r]));
            Done.insert(a[r]);
        }
        else
        {
            Extra.insert(a[r]);
        }
        // cout << Done << endl;
        ans += (Done.size() >= k);
    }
    cout << ans << endl;
}
