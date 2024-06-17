void solve()
{
    int n;
    cin >> n;
    vi b(n);
    read(b);
    fr(i, n)
    {
        b[i] -= i;
    }
    map<int, int> mp;
    fr(i, n)
    {
        mp[b[i]] += b[i] + i;
    }
    int mx=0;
    for(auto it:mp)
    {
        mx=max(mx,it.S);
    }
    cout<<mx;
}
