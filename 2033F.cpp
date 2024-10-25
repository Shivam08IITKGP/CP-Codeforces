void solve()
{
    int n, k;
    cin >> n >> k;
    int tmp = 0;
    int prem = 1 % k, nrem = 1 % k;
  // prem is previous term and nrem is the next term
    int cnt = 2;

    while (nrem != 0)
    {
        int tprem = nrem;
        nrem = (prem + nrem) % k;
        prem = tprem;
        cnt++;
    }

    if (k == 1)
    {
        cout << (n % N) << endl;
    }
    else
    {
        n %= N;
        cnt %= N;
        n *= cnt;
        n %= N;
        cout << n << endl;
    }
}
