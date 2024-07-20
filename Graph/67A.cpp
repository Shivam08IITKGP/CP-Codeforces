void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vi a(n, 1);

    for (int i = 1; i < n; i++)
    {
        if (s[i - 1] == 'L')
        {
            a[i - 1] = max(a[i] + 1, a[i - 1]);
        }
        if (s[i - 1] == 'R')
        {
            a[i] = max(a[i], a[i - 1] + 1);
        }
        if (s[i - 1] == '=')
        {
            a[i] = a[i - 1];
        }
    }

    for (int i = n - 2; i >= 0; i--)
    {
        if (s[i] == 'L')
        {
            a[i] = max(a[i], a[i + 1] + 1);
        }
        if (s[i] == 'R')
        {
            a[i + 1] = max(a[i + 1], a[i] + 1);
        }
        if (s[i] == '=')
        {
            a[i] = a[i + 1];
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
