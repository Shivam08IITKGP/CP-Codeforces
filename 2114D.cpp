void solve()
{
    int n;
    cin >> n;
    vi x(n), y(n);

    fr(i, n)
    {
        cin >> x[i] >> y[i];
    }
    if (n == 1)
    {
        cout << 1 << endl;
        return;
    }
    multiset<int> X, Y;
    fr(i, n)
    {
        X.insert(x[i]);
        Y.insert(y[i]);
    }

    int ans = (*X.rbegin() - *X.begin() + 1) * (*Y.rbegin() - *Y.begin() + 1);
    fr(i, n)
    {
        X.erase(X.find(x[i]));
        Y.erase(Y.find(y[i]));
        int h = (*X.rbegin() - *X.begin() + 1);
        int b = (*Y.rbegin() - *Y.begin() + 1);
        if (h * b == n - 1)
        {
            ans = min(ans, min((h + 1) * b, h * (b + 1)));
        }
        else
        {
            ans = min(ans, h * b);
        }
        X.insert(x[i]);
        Y.insert(y[i]);
    }
    cout << ans << endl;
}
