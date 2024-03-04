// Here in this problem only O(n) time complexity is accepted
// Also passing the vector by reference is also rejected
#include <bits/stdc++.h>
using namespace std;

#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long int ll;

void solve();
bool SubarrayExists(vector<ll> &arr, int n);
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
bool SubarrayExists(vector<ll> &arr, int n)
{
    set<ll> sumSet;
    sumSet.insert(0);

    // Traverse through array
    // and store prefix sums
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];

        // If prefix sum is 0 or
        // it is already present
        if (sum == 0 || sumSet.find(sum) != sumSet.end())
            return true;

        sumSet.insert(sum);
    }
    return false;
}
void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (i % 2)
            a[i] *= -1;
    }
    // (SubarrayExists(a,n))?cout<<"YES\n":cout<<"NO\n";
    set<ll> sumSet;
    sumSet.insert(0);

    // Traverse through array
    // and store prefix sums
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        if (sum == 0 || sumSet.find(sum) != sumSet.end())
        {
            cout << "YES\n";
            return;
        }
        sumSet.insert(sum);
    }
    cout << "NO\n";
}
