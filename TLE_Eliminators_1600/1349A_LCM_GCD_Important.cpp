 
int __lcm(int a, int b)
{
    return a * b / __gcd(a, b);
}
 
void solve()
{
    int n;
    cin >> n;
    vi a(n);
    read(a);
    vi prefgcd(n, a[0]), suffgcd(n, a[n - 1]);
    for (int i = 1; i < n; i++)
    {
        prefgcd[i] = __gcd(prefgcd[i - 1], a[i]);
        suffgcd[n - i - 1] = __gcd(suffgcd[n - i], a[n - i - 1]);
    }
    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            ans = __lcm(ans, suffgcd[1]);
        }
        else if (i == n - 1)
        {
            ans = __lcm(ans, prefgcd[n - 2]);
        }
        else
        {
            ans = __lcm(ans, (gcd(prefgcd[i - 1], suffgcd[i + 1])));
        }
    }
    cout << ans << endl;
}
