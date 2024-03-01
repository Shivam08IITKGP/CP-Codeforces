//O(m*d.size()*10)
#include <bits/stdc++.h>
using namespace std;
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long int ll;

void solve();
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
void solve()
{
    string d;
    cin >> d;
    int m;
    cin >> m;
    string lb, ub;
    cin >> lb >> ub;
    // Lower Bound and Upper Bound for every digits
    // Means the digit at position i should lie between lb[i] and ub[i]
    // current position is set to 1 because we are starting from cur_position + 1
    // if we start from 0 then we will have to check for the first character separately

    // We want the i-1th character to lie at the rightmost position in the string
    int cur_position = -1;

    for (int i = 0; i < m; i++)
    {
        int temp_position = cur_position + 1;
        for (char num = lb[i]; num <= ub[i]; num++)
        {
            int flag = 0;
            for (int k = cur_position + 1; k < d.size(); k++)
            {
                if (d[k] == num)
                {
                    temp_position = max(temp_position, k);
                    flag = 1;
                    break;
                }
            }
            if (!flag)
            {
                // If the character is not found in the string
                // Valid Password
                cout << "YES" << endl;
                return;
            }
        }
        cur_position = temp_position;
        if (i != 0 and cur_position >= d.size())
        {
            // If the current position is greater than the size of the string
            // Valid Password
            cout << "YES" << endl;
            return;
        }
    }
    // Every possible valid combinations are found in the string
    cout << "NO" << endl;
    return;
}
