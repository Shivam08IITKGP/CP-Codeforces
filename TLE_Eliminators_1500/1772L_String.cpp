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
    string s;
    cin >> s;
    ll minus = 0, plus = 0;
    for (int i = 0; i < n; i++)
    {
        minus += (s[i] == '-');
        plus += (s[i] == '+');
    }
    int q;
    cin >> q;
    while (q--)
    {
        ll x, y;
        cin >> x >> y;
        if (minus == plus)
        {
            cout << "YES\n";
            continue;
        }
        if (x > y)
        {
            swap(x, y);
        }
        ll ans = y * (plus - minus);
        if (y == x)
        {
            cout << "NO\n";
            continue;
        }
        if (ans % (y - x) == 0)
        {
            if (ans / (y - x) >= -minus and ans / (y - x) <= plus)
            {
                cout << "YES\n";
                continue;
            }
        }
        cout << "NO\n";
    }
}
// link to solution - https://codeforces.com/contest/1776/attachments/download/19130/solutions.pdf
int main()
{
    FAST;
    int t;
    // cin >> t;
    t = 1;
    while (t--)
    {
        solve();
    }
}
