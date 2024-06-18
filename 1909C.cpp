#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define b begin
#define e end
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

void solve()
{
    //This is a bracket matching problem of stack
    //Here the l elements are ( and r elements are )
    //We are doing this to find the minimum difference between the l and r elements
    
    //Sorting both the l and r elements and then finding the difference between the l and r elements
    //will not provide the lowest differences between the l and r elements


    ll n;
    cin >> n;
    vector<ll> l(n), r(n), c(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> l[i];
    }
    for (ll i = 0; i < n; i++)
    {
        cin >> r[i];
    }
    for (ll i = 0; i < n; i++)
    {
        cin >> c[i];
    }

    vector<pair<ll, char>> p;
    for (ll i = 0; i < n; i++)
    {
        p.push_back({l[i], 'l'});
        p.push_back({r[i], 'r'});
    }
    vector<ll> diff;
    stack<pair<ll, char>> s;
    sort(p.b(), p.e());
    ll ans = 0;
    for (ll i = 0; i < 2 * n; i++)
    {
        if (p[i].second == 'l')
            s.push(p[i]);
        else
        {
            ll x = s.top().first;
            s.pop();
            diff.push_back(p[i].first - x);
        }
    }
    sort(c.b(), c.e(), greater<ll>());
    sort(diff.b(), diff.e());
    for (ll i = 0; i < n; i++)
    {
        ans += c[i] * diff[i];
    }
    cout << ans << endl;
}
int main()
{
    FAST
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
