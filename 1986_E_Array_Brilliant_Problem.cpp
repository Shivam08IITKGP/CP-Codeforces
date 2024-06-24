void solve()
{
    ll n, k;
    cin >> n >> k;
    vll array(n);
    map<ll, vll> remainder_map;

    for (ll i = 0; i < n; ++i)
    {
        cin >> array[i];
        remainder_map[array[i] % k].pb(array[i]);
    }

    ll odd_count = 0;
    ll total_operations = 0;

    for (auto it : remainder_map)
    {
        sort(all(it.second));
        ll size = it.second.size();

        if (size % 2 != 0)
            odd_count++;

        if (odd_count > 1)
        {
            cout << -1 << endl;
            return;
        }

        if (size % 2 != 0)
        {
            ll temp = 0;
            for (ll j = 0; j < size - 1; j += 2)
            {
                temp += (it.second[j + 1] - it.second[j]) / k;
            }

            ll min_operations = temp;

            for (ll j = size - 2; j >= 0; --j)
            {
                if (j % 2 == 0)
                    temp -= (it.second[j + 1] - it.second[j]) / k;
                else if (j & 1)
                    temp += (it.second[j + 1] - it.second[j]) / k;

                min_operations = min(min_operations, temp);
            }

            total_operations += min_operations;
        }
        else
        {
            for (ll j = 0; j < size - 1; j += 2)
            {
                total_operations += (it.second[j + 1] - it.second[j]) / k;
            }
        }
    }

    cout << total_operations << endl;
}
