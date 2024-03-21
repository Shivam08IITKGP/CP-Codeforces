#include <bits/stdc++.h>
using namespace std;

#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long int ll;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int last_element_position = n - 1;
    vector<bool> visited(n, false);
    while (k--)
    {
        if (a[last_element_position] > n)
        {
            cout << "NO" << endl;
            return;
        }
        else if (visited[last_element_position])
        {
            cout << "YES" << endl;
            return;
        }
        else
        {
            visited[last_element_position] = true;
            last_element_position = (last_element_position - a[last_element_position] + n) % n;
        }
    }
    cout << "Yes" << endl;
    return;
}
// Why are we looking only for last position element?
// Because after left shift x times the element a[x] will be at the last position
// So we are backtracking on operations (left shift x times)


// 4 3 3 2 3
// k = 3
// now last_element_position is 4  -> here x is now 3
// now last_element_position is 1  -> here x is now 3
// now last_element_position is 3  -> here x is now 2
// Original array -> 3 2 3 4 3

// 3 2 3 4 3 -> Left shift 2 times -> 3 4 3 3 2
// -> Left shift 3 times -> 3 2 3 4 3
// -> Left shift 3 times -> 4 3 3 2 3 

// If we reach the same spot then there will be a cycle
// If a[last_element_position] <= n, then we can left shift
// If a[last_element_position] > n, then the left shift is not possible
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
