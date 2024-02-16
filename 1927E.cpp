#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    ll l = 1, r = n;
    for (ll i = 0; i < k; i++)
    {
        for (ll j = i; j < n; j += k)
        {
            if (j & 1)
            {
                a[j] = r--;
            }
            else
            {
                a[j] = l++;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
int main()
{
    FASTIO;
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
