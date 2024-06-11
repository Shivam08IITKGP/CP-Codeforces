// Simply check if in every number there is a bit that is unique to only that number
// If every number has such a unique bit, then answer is no
// Else YES
//Note that the bit can be greater than 32
// Hence used a map

void solve()
{
    int n;
    cin >> n;

    vi bits[n];
    map<int,int>m;
    for (int i = 0; i < n; i++)
    {
        int k;
        read(k);
        while (k--)
        {
            int x;
            cin >> x;
            bits[i].pb(x);
            m[x]++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        bool present= false;
        for(auto j:bits[i])
        {
            if(m[j]==1)
            {
                present= true;
            }
        }
        if(!present)
        {
            cout<<"YES\n";
            return;
        }


    }
    cout<<"NO\n";
    return;
}
