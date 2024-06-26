void solve()
{
    int n, k;
    string s;
    read(n, k, s);

    int cnt = 1, p = -1;
    rep(i, 1, n - 1)
    {
        if (s[i] == s[i - 1])
            cnt++;
        else
        {
            if (cnt != k)
            {
                // if cnt!=k then why are we making p= i???
                // Because We must remove this part And shift it to back 
                // As this can't represent the front
                p = i;
                if (cnt > k)
                // if cnt>=2k then answer is -1 only
                // we are just seperating the string
                    p -= k;
                break;
            }
            else
            {
                cnt = 1;
            }
        }
    }
    if (p == -1 and cnt != k)
    {
        cout << -1 << endl;
        return;
    }
    if (p == -1)
    {
        cout << n << endl;
        return;
    }
    vector<char> ans(n);
    fr(i, n - p) ans[i] = s[i + p];
    fr(i, p) ans[n - i - 1] = s[i];

    fr(i, k - 1) if (ans[i] != ans[i + 1])
    {
        cout << -1 << endl;
        return;
    }
    fr(i, n - k) if (ans[i] == ans[i + k])
    {
        cout << -1 << endl;
        return;
    }
    cout << p << endl;
}
