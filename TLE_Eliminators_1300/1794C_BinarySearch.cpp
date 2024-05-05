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

vi ans;
vi a;
void solve_nlogn()
{
    ll n;
    cin >> n;
    a.resize(n);
    ans.clear();

    f(i, 0, n)
    {
        cin >> a[i];
    }
    f(i, 0, n)
    {
        ll l = 1, r = 1 + i;
        while (l <= r)
        {
            ll m = (l + r) / 2;
            if (a[i + 1 - m] >= m)
            {
                l = m + 1;
            }
            else
                r = m - 1;
        }
        ans.push_back(r);
    }

    f(i, 0, n)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}
void solve_nsquare()
{
    ll n;
    cin >> n;
    a.resize(n);
    ans.assign(n, 0);

    f(i, 0, n)
    {
        cin >> a[i];
        f(j, i, min(i + a[i], n))
        {
            ans[j]++;
        }
    }
    f(i, 0, n)
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
        solve_nlogn();
    }
}
