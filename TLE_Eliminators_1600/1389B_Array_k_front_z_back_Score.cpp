void solve()
{
    int n, k, z;
    cin >> n >> k >> z;
    vi a(n);
    read(a);
 
    vi prefSum(n);
    prefSum[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        prefSum[i] = prefSum[i - 1] + a[i];
    }
 
    int ans = 0;
    for (int t = 0; t <= z; t++)
    {
        int moves_right = k - 2 * t;
        if (moves_right < 0)
            continue;
        int current_sum = prefSum[moves_right];
        int best_pair_sum = 0;
        for (int i = 0; i <= moves_right; i++)
        {
            if (i + 1 < n)
            {
                best_pair_sum = max(best_pair_sum, a[i] + a[i + 1]);
            }
        }
        current_sum += t * best_pair_sum;
        remax(ans, current_sum);
    }
 
    cout << ans << endl;
}
