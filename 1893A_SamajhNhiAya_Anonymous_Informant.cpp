#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    int pos = n - 1;
    vector<bool>visited(n, false);
    while (k--)
    {
        if (b[pos] > n)
        {
            cout << "No" << endl;
            return;
        }
        if (visited[pos])
        {
            cout << "Yes" << endl;
            return;
        }
        visited[pos] = true;
        pos = (pos - b[pos] + n) % n;
    }
    cout << "Yes" << endl;
    return;
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
