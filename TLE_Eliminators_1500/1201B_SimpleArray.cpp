void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    read(a);
    int sum = accumulate(all(a), 0LL);
    if (sum % 2 == 0 and 2 * (*max_element(all(a))) <= sum)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
}
