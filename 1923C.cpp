#include <bits/stdc++.h>
using namespace std;

#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long int ll;
vector<ll> a;

void solve()
{
    int n, q;
    cin >> n >> q;
    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    ll totalSum[n + 1];
    int cnt_ones[n + 1];

    totalSum[0] = cnt_ones[0] = 0;
    for (int i = 0; i < n; i++)
    {
        cnt_ones[i + 1] = (a[i] == 1) + cnt_ones[i];
        totalSum[i + 1] = a[i] + totalSum[i];
    }

    while (q--)
    {
        int l, r;
        cin >> l >> r;

        if (r == l)
        {
            cout << "NO" << endl;
            continue;
        }
        // We will find the array where all the non-1 elements are replaced by 1
        // and all the 1's are replaced by 2
        // Hence the sum of the new subarray will be (r-l+1)+ Count_ones
        // If the sum of the original subarray is greater than or equal to the sum of the new subarray
        // Then the answer is YES
        // Otherwise the answer is NO
        ll sum = totalSum[r] - totalSum[l - 1];
        int Count_ones = cnt_ones[r] - cnt_ones[l - 1];
        if (sum >= Count_ones + (r - l + 1))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
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
