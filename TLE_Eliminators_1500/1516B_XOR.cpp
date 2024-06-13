void solve()
{
    int n;
    read(n);
    vi a(n);
    for (int i = 0; i < n; i++)
        read(a[i]);

    int overallXOR = 0;
    for (int i = 0; i < n; i++)
    {
        overallXOR ^= a[i];
    }

    // If at last only two equal elements remain then XOR=0
    if (overallXOR == 0)
    {
        cout << "YES\n";
        return;
    }

    int prefixXOR = 0;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        prefixXOR ^= a[i];
        if (prefixXOR == overallXOR)
        {
            count++;
            prefixXOR = 0;
        }
    }
    // We need three partitions which have the same value of XOR
    // Their XOR will be the be the number itself i.e. overallXOR
    // Hence we try to find the number of partitions whose XOR = overallXOR
    if (count >= 2)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
}
