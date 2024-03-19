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
    cin >> n;

    string s;
    cin >> s;

    vector<int> prefix_count_ones(n);
    prefix_count_ones[0] = s[0] == '1';
    for (int i = 1; i < n; i++)
    {
        prefix_count_ones[i] = prefix_count_ones[i - 1] + (s[i] == '1');
    }
    // prefix_count_ones[i] = number of 1s till i

    // count_ones is a lambda function that returns the number of 1s between l and r
    auto count_ones = [&](int l, int r)
    {
        if (l == 0)
            return prefix_count_ones[r];
        return prefix_count_ones[r] - prefix_count_ones[l - 1];
    };

    int ans = -1;

    // If the number of 1s is already greater than or equal to half of the total number of elements
    // then no need to place the road before the index 0
    // else we might need to place the road before the index 0
    if (count_ones(0, n - 1) >= (n + 1) / 2)
    {
        ans = 0;
    }

    for (int i = 0; i < n; i++)
    {
        // left1 = number of 1s till i
        int left1 = count_ones(0, i);
        // left0 = number of 0s till i
        int left0 = i + 1 - left1;
        // right1 = number of 1s after i
        int right1 = count_ones(i + 1, n - 1);
        // right0 = number of 0s after i
        int right0 = n - i - 1 - right1;

        // This is the best way to check left0 is atleast half of the total number of ones
        // Check it with left1.
        // No confusion of ceil or floor , even or odd

        if (left0 >= left1 && right1 >= right0)
        {
            //  Also this is the best way to take round of
            //  Multiply expression by 2 to compare
            if (abs(n - 2 * (i + 1)) < abs(n - 2 * ans))
            {
                ans = i + 1;
            }
        }
    }

    if (ans == -1)
        // Partition before the first house
        ans = 0;
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
