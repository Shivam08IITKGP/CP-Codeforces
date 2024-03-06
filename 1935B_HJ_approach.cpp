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
    int a[n + 1];
    vector<int> num(n, 0);
    int left[n], right[n];
    // Left array is storing the leftmost position of the index it is on
    // Similarly the right array is storing the rightmost position
    // of the index it is on
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        num[a[i]]++;
        if (num[a[i]] == 1)
            left[a[i]] = i;
        right[a[i]] = i;
    }

    int mex = -1;
    for (int i = 0; i < n; i++)
    {
        if (num[i] == 0)
        {
            mex = i;
            break;
        }
    }

    if (mex == -1)
    {
        // This is for the case 0 1 2 3 4
        cout << -1 << endl;
        return;
    }

    if (mex == 0)
    {
        cout << 2 << endl;
        cout << 1 << " " << 1 << endl;
        cout << 2 << " " << n << endl;
        return;
    }
    // Atleast one occurences of all the terms
    // smaller than mex should lie behind the rightmost occurences of them
    // maxleft is the maximum leftmost position of the number smaller
    // than the mex
    // minright is the minimum rightmost position of the number smaller
    // than the mex
    int maxleft = INT_MIN;
    int minright = INT_MAX;

    for (int i = 0; i < mex; i++)
    {
        maxleft = max(maxleft, left[i]);
        minright = min(minright, right[i]);
    }

    if (maxleft >= minright)
    {
        cout << -1 << endl;
        return;
    }

    cout << 2 << endl;
    cout << 1 << " " << maxleft << endl;
    cout << maxleft + 1 << " " << n << endl;
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
