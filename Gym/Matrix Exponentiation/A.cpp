void solve()
{
    int n;
    double p;
    read(n, p);
 
    double prob = 1.0;
    while(n>0)
    {
        if(n%2==1)
        {
            prob = prob*(1-p) + (1-prob)*p;
        }
        p = p*(1-p) + (1-p)*p;
        n/=2;
    }
    cout<<fixed<<setprecision(10)<<prob<<endl;
}
 
