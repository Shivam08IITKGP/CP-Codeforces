#include <bits/stdc++.h>
using namespace std;
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long int ll;

void solve()
{
    int n;
    string s;
    cin >> s;
    n = s.size();
    int ans = 0;

    for (int d = 1; d < n; d++)
    {
        int count = 0;
        for (int i = 0; i < n - d; i++)
        {
            count += (s[i] == s[i + d]) or (s[i] == '?') or (s[i + d] == '?');
            if (i - d >= 0)
            {
                // Now we are on a string i, i+d , so we need to delete the string (reduce the count) on i-d,i

                count -= s[i - d] == s[i] or s[i - d] == '?' or s[i] == '?';
            }
            // If we find a suffix string that is matching with the prefix string, then the length will be 2*d
            if (i - d >= -1 and count == d)
            {
                ans = 2 * d;
                break;
            }
        }
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
    return 0;
}
