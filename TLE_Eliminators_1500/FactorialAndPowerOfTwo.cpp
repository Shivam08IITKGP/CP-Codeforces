void solve()
{
    int n;
    cin >> n;
    int ans = INT_MAX;
    vi power;
    int fact = 2;
    int bipn = __builtin_popcountll(n);
    for (int i = 3; i < 15; i++)
    {
        fact *= (i);
        if (fact <= n)
            power.pb(fact);
        else
            break;
    }
    for (int i = 0; i < (1LL << power.size()); i++)
    {
        int number = 0;
        int cnt1 = 0;
        for (int j = 0; j < power.size(); j++)
        {
            if ((i >> j) & 1)
            {
                number += power[j];
                cnt1++;
            }
        }
        if (number > n)
        {
            continue;
        }
        int cnt = __builtin_popcountll(n-number);
        remin(ans, cnt + cnt1);
    }
    cout << ans << endl;
}
