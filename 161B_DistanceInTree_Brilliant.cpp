#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define f(i, start, end) for (ll i = start; i < end; i++)
#define fr(i, start, end) for (ll i = start; i > end; i--)
#define vll vector<ll>
#define pll pair<ll, ll>
#define vi vector<int>
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long int ll;

ll ans = 0;
void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<int> adj[n + 1];
    f(i, 0, n - 1)
    {
        ll u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    // ll distance = 0;

    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

    function<void(ll, int)> dfs = [&](ll node, int parent)
    {
        dp[node][0] = 1;
        for (auto child : adj[node])
        {
            if (child == parent)
            {
                continue;
            }
            dfs(child, node);
            // those nodes which are at distance i from child node
            // and having distance k-i-1 from the current node
            // are at a distance k from each other
            f(i, 0, k) ans += dp[node][i] * dp[child][k - i - 1];
            f(i, 0, k) dp[node][i + 1] += dp[child][i];
            // You might be thinking that if distance from one node is k-i-1 and another is i,
            // so can they not lie in near to each other i.e. same path?
            // We are adding the dp[child][i] only after we have calculated the ans for all the nodes
            // that are not in the child path.
            // So, we are not counting the nodes that are in the child path.
        }
    };
    dfs(1, -1);
    cout << ans << endl;
}

int main()
{
    FAST;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}
