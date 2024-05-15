#include <bits/stdc++.h>
using namespace std;
// Time complexity is O((n+q)log(n))
// Space complexity is O(n)
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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    string s;
    cin >> s;
    vector<int> prefix(n + 1);
    prefix[0] = 0;
    for (int i = 0; i < n; i++)
    {
        prefix[i + 1] = prefix[i] ^ a[i];
    }

    int xor_zero = 0, xor_one = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {
            xor_zero ^= a[i];
        }
        else
        {
            xor_one ^= a[i];
        }
    }

    int q;
    cin >> q;
    while (q--)
    {
        int queryType;
        cin >> queryType;
        if (queryType == 2)
        {
            int g;
            cin >> g;
            if (g == 0)
            {
                cout << xor_zero << " ";
            }
            else
            {
                cout << xor_one << " ";
            }
        }
        else if (queryType == 1)
        {
            int l, r;
            cin >> l >> r;
            xor_zero = (xor_zero ^ (prefix[r] ^ prefix[l - 1]));
            xor_one = (xor_one ^ (prefix[r] ^ prefix[l - 1]));
        }
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
