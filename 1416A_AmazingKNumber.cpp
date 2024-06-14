void solve()
{
    int n;
    cin >> n;
    vi a(n + 1);
    rep(i, 1, n)
    {
        cin >> a[i];
    }
    vi f(n + 1, 0), last(n + 1, 0), ans(n + 1, -1);

    rep(i, 1, n)
    {
        int x = a[i];
        f[x] = max(f[x], i - last[x]);
        last[x] = i;
    }


    for (int x = 1; x <= n; x++)
    {
        remax(f[x], n - last[x] + 1);
        //This loop goes until ans[i]!=-1
        //It only runs if we find an x which is smaller than the previous x's f[x]

        //We are asked the minimum of the intersection, not the minimum of *every* 
        //subarrays
        //Hence we start from x=1 to n
        //x is the element
        for (int i = f[x]; i <= n and ans[i] == -1; i++)
        {
            ans[i] = x;
        }
    }
    
    /* The code snippet you provided is printing out information about the last occurrence of each
    element `x` and the largest gap between consecutive occurrences of each element `x`. */
    
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << "last occurence of x = "<<i<<" is "<<last[i] << endl;
    // }
    // cout << endl;
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << "largest gap between consecutive x = "<<i<<" is "<<f[i] << endl;
    // }
    // cout << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}
