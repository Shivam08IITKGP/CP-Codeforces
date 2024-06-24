void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vi a(n);
    fr(i, n)
    {
        a[i] = s[i] - '0';
    }
    if (n == 2)
    {
        cout << 10 * a[0] + a[1] << endl;
        return;
    }
    int sum = INT_MAX;

    vi temp;
    fr(i, n - 1)
    {
        int num = a[i] * 10 + a[i + 1];
        fr(j, i)
        {
            temp.pb(a[j]);
        }
        temp.pb(num);
        for (int j = i + 2; j < n; j++)
        {
            temp.pb(a[j]);
        }
        int sum_ = 0;
        if (count(all(temp), 0))
        {
            cout << 0 << endl;
            return;
        }
        if (count(all(temp), 1) == n - 1)
        {
            sum = min(sum, 1LL);
            continue;
        }
        else
        {
            fr(j, temp.size())
            {
                if (temp[j] != 1)
                    sum_ += temp[j];
            }
            sum = min(sum_, sum);
        }
        temp.resize(0);
    }

    cout << sum << endl;
}
