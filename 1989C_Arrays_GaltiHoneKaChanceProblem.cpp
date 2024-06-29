void solve()
{
    int n;
    cin >> n;
    vii p(n);
    for (int i = 0; i < n; i++)
    {
        cin >> p[i].F;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> p[i].S;
    }
    // if (n == 1)
    // {
    //     if (p[0].F == -1 and p[0].S == -1)
    //     {
    //         cout << -1 << endl;
    //         return;
    //     }
    //     else
    //     {
    //         cout << 0 << endl;
    //         return;
    //     }
    // }

    int x = 0, y = 0;
    int pos = 0, neg = 0;
    fr(i, n)
    {
        if (p[i].F == 1 and p[i].S == 1)
        {
            pos++;
        }
        else if (p[i].F == -1 and p[i].S == -1)
        {
            neg++;
        }
        else if (p[i].F > p[i].S)
        {
            x += p[i].F;
        }
        else if (p[i].F < p[i].S)
        {
            y += p[i].S;
        }
    }
    int ans = INT_MIN;

    for (int i = -neg; i <= pos; i++)
    {
        remax(ans, min(x + i, y + (pos - neg - i)));
    }
    cout << ans << endl;
}
