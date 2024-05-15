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
    ll k, pos1, pos2;
    cin >> k >> pos1 >> pos2;
    vector<ll> p(n);
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<ll> travel(n);
    vector<ll> position(n);
    ll ans1 = 0, ans2 = 0;
    position[0] = pos1;      // 3
    travel[0] = 0; // 5
    for (ll i = 1; i < min(n, k); i++)
    {
        position[i] = p[position[i - 1] - 1];
        travel[i] = travel[i - 1] + a[position[i -1] - 1];
    }
    for (ll i = 0; i < min(n, k); i++)
    {
        ans1 = max(ans1, (k - i) * a[position[i] - 1] + travel[i]);
    }
    position[0] = pos2;
    travel[0] = 0;
    for (ll i = 1; i < min(n, k); i++)
    {
        position[i] = p[position[i - 1] - 1];
        travel[i] = travel[i - 1] + a[position[i-1] - 1];
    }
    for (ll i = 0; i < min(n, k); i++)
    {
        ans2 = max(ans2, (k - i) * a[position[i] - 1] + travel[i]);
    }
    // cout << ans1 << " " << ans2 << endl;
    if (ans1 == ans2)
    {
        cout << "Draw\n";
    }
    else if (ans1 > ans2)
    {
        cout << "Bodya\n";
    }
    else
    {
        cout << "Sasha\n";
    }
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
