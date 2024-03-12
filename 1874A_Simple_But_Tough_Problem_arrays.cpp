#include <bits/stdc++.h>

using namespace std;
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long int ll;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n), b(m);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    int x = 0, y = 0;
    for (int i = 1; i < n; i++)
        if (a[i] < a[x])
            x = i;
    for (int i = 1; i < m; i++)
        if (b[i] > b[y])
            y = i;
    // Simple approach
    //  1) If k is odd then
    //   if max(b)>min(a), then swap these two elements
    //     else no swapping
    //
    //  Odd move is the first move always

    // then
    //
    //  2) If k is even then
    //  now the max(a) is definitely greater than min(b), as in the odd step,
    //  if earlier than the odd step if max(b)>min(a) then we swap (Hence the max of b has gone to a)
    //  else also (there exists a number in a which is greater than b)

    //  Hence swap max(a),min(b)

    if (b[y] > a[x])
        swap(a[x], b[y]);
    if (!(k & 1))
    {
        x = 0, y = 0;
        for (int i = 1; i < n; i++)
            if (a[i] > a[x])
                x = i;
        for (int i = 1; i < m; i++)
            if (b[i] < b[y])
                y = i;
        swap(a[x], b[y]);
    }
    ll ans = 0;
    for (int i = 0; i < n; i++)
        ans += a[i];
    cout << ans << endl;
}

int main()
{
    FAST;
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
