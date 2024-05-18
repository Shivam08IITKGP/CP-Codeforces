#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define f(i, start, end) for (ll i = start; i < end; i++)
#define fr(i, start, end) for (ll i = start; i > end; i--)
#define vll vector<ll>
#define pll pair<ll, ll>
#define vi vector<int>
#define v vector
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long int ll;

void solve()
{
    ll n;
    cin >> n;
    vll a(n);
    ll index = -1;
    f(i, 0, n)
    {
        cin >> a[i];
        if (a[i] == 1)
            index = i;
    }

    vector<pll> high(n / 2), low(n / 2);
    if (index % 2 == 0)
    {
        for (int i = 0; i < n; i += 2)
        {
            low[i / 2] = {a[i], i};
            high[i / 2] = {a[i + 1], i + 1};
        }
    }
    else
    {
        for (int i = 0; i < n; i += 2)
        {
            low[i / 2] = {a[i + 1], i + 1};
            high[i / 2] = {a[i], i};
        }
    }
    sort(high.begin(), high.end());
    sort(low.begin(), low.end());
    vll ans(n);
    ll j = n;
    for (int i = 0; i < n / 2; i++)
    {
        ans[high[i].second] = j--;
    }
    for (int i = 0; i < n / 2; i++)
    {
        ans[low[i].second] = j--;
    }
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main()
{
    FAST;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
