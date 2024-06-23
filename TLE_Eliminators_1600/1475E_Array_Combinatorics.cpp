int fact(int n)
{
    if (n == 0 or n == 1)
        return 1;
    int temp = n;
    for (int i = 2; i < n; i++)
    {
        temp *= i;
        temp %= N;
    }
    return temp;
}
int nCk(int n, int k)
{
    return (((fact(n) * (binpow(fact(n - k), N - 2, N))) % N) * (binpow(fact(k), N - 2, N)) % N);
}
 
void solve()
{
    int n, k;
    cin >> n >> k;
    vi a(n);
    vi cnt(1 + n, 0);
    fr(i, n)
    {
        cin >> a[i];
        cnt[a[i]]++;
    }
 
    for (int i = n; i > 0; i--)
    {
        if (cnt[i] >= k)
        {
            cout << nCk(cnt[i], k) << endl;
            return;
        }
        else
        {
            k -= cnt[i];
        }
    }
    cout << 1 << endl;
}
