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

vll a;
vll cnt;

void solve()
{
    ll n, m;
    cin >> n >> m;
    a.assign(m + 1, 0);
    cnt.assign(n + 1, 0);
    f(i, 0, m)
    {
        cin >> a[i];
        cnt[a[i]]++;
    }
    ll l = 0, r = 2 * m;
    ll incomplete = m;
    ll last = 2 * m;
    while (l <= r)
    {
        incomplete = m;
        ll t = (l + r) / 2;

        f(i, 1, n + 1)
        {
          // Complete this much of proficient tasks (take 1 hour)
            incomplete -= min(cnt[i], t);
          // Complete this much of non proficient tasks (take 2 hours)
            incomplete -= (t - min(cnt[i], t)) / 2;
        }
        if (incomplete <= 0)
        {
            r = t - 1;
        }
        else
            l = t + 1;
        last = t;
    }
    cout << r+1 << endl;
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
