void solve()
{
    int n;
    cin >> n;
    vi a(n);
    vi freq(n + 1, 0);
    fr(i, n)
    {
        cin >> a[i];
        freq[a[i]]++;
    }
    vi st;
    fr(i, n + 1)
    {
        if (freq[i])
        {
            st.pb(freq[i]);
        }
    }
    sort(rall(st));

    int ans = 0;
    int lst = -1;
    for (auto &it : st)
    {
        if (lst == -1)
        {
            lst = it;
            ans += lst;
            continue;
        }
        else
        {
            if (lst == 1)
            {
                break;
            }
            ans += min(lst - 1, it);
            lst = min(it, lst - 1);
        }
    }
    cout << ans << endl;
}
