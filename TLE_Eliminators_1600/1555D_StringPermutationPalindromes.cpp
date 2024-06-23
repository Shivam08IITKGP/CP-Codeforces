void solve()
{
    int n, q;
    read(n, q);
    string s;
    cin >> s;
 
    vector<vector<int>> pref(6, vector<int>(n + 1));
    string t = "abc";
    int cur = 0;
    do
    {
        for (int i = 0; i < n; ++i)
            pref[cur][i + 1] = pref[cur][i] + (s[i] != t[i % 3]);
        ++cur;
    } while (next_permutation(all(t)));
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        int ans = n;
        for (int i = 0; i < 6; ++i)
            ans = min(ans, pref[i][r] - pref[i][l - 1]);
        cout << ans << endl;
    }
}
