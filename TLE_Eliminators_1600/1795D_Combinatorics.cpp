ll binpow(ll b, ll p)
{
    ll ans = 1;
    ;
    for (; p; p >>= 1)
    {
        if (p & 1)
            ans = ans * b;
        b = b * b;
    }
    return ans;
}

long long binpow(long long a, long long b, long long m)
{
    a %= m;
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int multiply(int a, int b)
{
    return (a * b) % M;
}
int inv(int a)
{
    return binpow(a, M - 2, M);
}

int divide(int a, int b)
{
    return (a * inv(b)) % M;
}

int nCr(int n, int r)
{
    if (r > n)
        return 0;
    if (r == 0 || r == n)
        return 1;
    int num = 1, denom = 1;
    for (int i = 0; i < r; ++i)
    {
        num = multiply(num, n - i);
        denom = multiply(denom, i + 1);
    }
    return divide(num, denom);
}

void solve()
{
    int n;
    cin >> n;
    vi a(n);
    read(a);
    if (n % 3 != 0)
    {
        cout << 0 << endl;
        return;
    }

    int ans = nCr(n / 3, n / 6);

    for (int i = 0; i < n; i += 3)
    {
        int c[3] = {a[i], a[i + 1], a[i + 2]};
        sort(c, c + 3);
        if (c[0] == c[1] and c[1] == c[2])
        {
            ans = (ans * 3) % M;
        }
        else if (c[0] == c[1])
        {
            ans = (ans * 2) % M;
        }
    }
    cout << ans << endl;
}
