#include <bits/stdc++.h>
using namespace std;

#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long int ll;
void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    vector<int> a_index_after_sorting(n);
    iota(a_index_after_sorting.begin(), a_index_after_sorting.end(), 0);
    sort(a_index_after_sorting.begin(), a_index_after_sorting.end(), [&](int i, int j)
         { return a[i] < a[j]; });

    sort(b.begin(), b.end());
    vector<int> ans(n);

    for (int i = 0; i < x; i++)
    {
        // n - x + i means the last x elements of a
        // a_index_after_sorting[n - x + i] means the index of the last x elements of a
        // Put the smallest x elements of b.
        ans[a_index_after_sorting[n - x + i]] = b[i];
    }
    for (int i = x; i < n; i++)
    {
        // i - x means the first n - x elements of a
        // a_index_after_sorting[i - x] means the index of the first n-x elements of a
        // Put the next n-x elements of b in the ans array.
        ans[a_index_after_sorting[i - x]] = b[i];
    }

    // Basically if a was sorted and we represent b as b1,b2,.... such that bi represent sorted b elements
    // Then ans will be b(x+1),b(x+2),....,b(n),b1,b2,...,b(x)
    for (int i = 0; i < n; i++)
    {
        x -= a[i] > ans[i];
    }
    if (x == 0)
    {
        cout << "YES\n";
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "NO\n";
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
