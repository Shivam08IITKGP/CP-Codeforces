void solve()
{
    int n, m;
    cin >> n >> m;
    if (m == 0)
    {
        cout << n << endl;
        return;
    }
    int ans = n;
    // ans|= 1LL;

    vector<bool> present(32, false);
    present[0] = true;
    int high= n+m;
    int low= max(0LL,n-m);
    int total = high-low;
    if(low) total++;


    for(int i=1;i<32;i++)
    {
        if(n & (1LL<<i))
        {
            present[i] = true;
            continue;
        }
        if(total>=(1LL<<i))
        {
            present[i]=true;
            continue;
        }
        else if(low%(1LL<<i)>high%(1LL<<i))
        {
            present[i]=true;
            continue;
        }

    }
    for (int i = 0; i < 32; i++)
    {
        if (present[i])
        {
            ans |= 1LL << i;
        }
    }
    cout << ans << endl;
}
