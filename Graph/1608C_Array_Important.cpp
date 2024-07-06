void solve()
{

    int n;
    cin >> n;
    vii a(n), b(n);

    fr(i, n)
    {
        cin >> a[i].F;
        a[i].S = i;
    }
    fr(i, n)
    {
        cin >> b[i].F;
        b[i].S = i;
    }

    sort(rall(a));
    sort(rall(b));

    set<int>ind;
    for(int i=0;i<n;i++)
    {
        ind.insert(a[i].S);
        ind.insert(b[i].S);

        // Total number of unique winners till index i
        // Means the numbers in ind are winners
        // The iteration stop here because there is no edge
        // from the latter part of the array to this part of the
        // array (considering an edge to be directed from u to v
        // if u can win over v
        if(ind.size()==i+1)
        {
            break;
        }
    }
    fr(i,n)
    {
        if(ind.find(i)==ind.end())
        {
            cout<<0;
        }
        else
        {
            cout<<1;
        }
    }
    cout<<endl;

}
