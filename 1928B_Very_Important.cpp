//Here the calculation of answer variable is a O(n^2) approach
//And also see the rest of the code implementation
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
    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    a.resize(unique(a.begin(), a.end()) - a.begin());
    // We are removing the duplicates from the array
    // Because they will not generate the same element after adding the permutations
    // As no two permutations are equal.

    int pnt = 0, ans = 0;
    // ans = Maximum size of subarray that will contain unique elements
    // by adding suitable numbers to each element
    // pnt = pointer to the start of the subarray
    // pnt is used to keep track of the start of the subarray
    // and i keeps track of the end of the subarray
    
    for (int i = 0; i < a.size(); i++)
    {
        while (a[i] - a[pnt] >= n)
        {
            pnt++;
        }
        ans = max(ans, i - pnt + 1);
    }
    cout << ans << endl;
}
int main()
{
    FAST int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
