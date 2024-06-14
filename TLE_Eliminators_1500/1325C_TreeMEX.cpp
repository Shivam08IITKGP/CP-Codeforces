void solve()
{
    int n;
    read(n);
    vector<int> edges[n+1];
    for (int i = 0; i <= n - 2; i++)
    {
        int u, v;
        cin >> u >> v;
        edges[u].pb(i);
        edges[v].pb(i);
    }

    ii mx = {0, 0};
    vector<int> ans(n - 1,-1);
    for (int i = 1; i <= n; i++)
    {
        mx = max(mx, {edges[i].size(), i});
    }
    int curr = 0;
    for (int i : edges[mx.second])
    {
        ans[i] = curr++;
    }
    for(int i=0;i<n-1;i++)
    {
        if(ans[i]==-1)
        {
            ans[i]=curr++;
        }
        cout<<ans[i]<<endl;
    }
    cout<<endl;

    // I don't want to make the MEX of maximum path to be minimum,
    // I want the maximum of MEX between any two nodes over all the nc2 combinations
    // to be minimum
    // So that's why 
    // We are making the edges connected to the node which has maximum edges connected to it
    // as 0 , 1 ,2 .....
    // and not the leaf edge as 0
    // if the tree is a bamboo, then no matter what there will be a n-1 mex path
    // otherwise the maximum mex possible is 2

 

}
