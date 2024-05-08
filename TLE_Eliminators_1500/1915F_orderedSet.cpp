#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;
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
//Meeting only possible when one track is inside the other
// Also we will use ordered_set which is similar to sorted set
// The order of key in it is a tool that tells the parameter's index in the sorted array if it was in the array.

void solve()
{
    ll n;
    cin >> n;
    ordered_set st;
    v<pll> a(n);
    f(i, 0, n)
    {
        cin >> a[i].second >> a[i].first;
    }
    sort(a.begin(), a.end());
    ll ans = 0;
    for (auto p : a)
    {
        ans += st.size() - st.order_of_key(p.second);
        // cout<<"order of key = "<<st.order_of_key(p.second)<<endl<<"element = "<<p.second<<endl;
        st.insert(p.second);
        // cout<<ans<<" ";
    }
    cout << ans << endl;
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
