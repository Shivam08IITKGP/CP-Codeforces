#include <bits/stdc++.h>
using namespace std;
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long int ll;

int find_MEX(vector<int> &a)
{
    int n = a.size();
    vector<int> cnt(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        if (a[i] < n)
        {
            cnt[a[i]]++;
        }
    }
    for (int i = 0; i <= n; i++)
    {
        if (cnt[i] == 0)
        {
            return i;
        }
    }
    return n;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int mini = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        mini = min(mini, a[i]);
    }
    if (mini == 0)
    {
        int mex = find_MEX(a);
        int count = 0;
        vector<pair<int, int>> ans;
        vector<bool> avail(n + 1, false);
        int l = 0, r;
        for (int i = 0; i < n; i++)
        {
            if (a[i] < mex and !avail[a[i]])
            {

                avail[a[i]] = true;
                count++;
                if (count == mex)
                {
                    r = i;
                    avail.assign(n + 1, false);
                    ans.push_back({l + 1, r + 1});
                    l = i + 1;
                    count = 0;
                }
            }
        }
        
        if (ans.size() <= 1 or l<r)
            cout << -1 << endl;
        else
        {
            cout << ans.size() << endl;
            for (int i = 0; i < ans.size(); i++)
            {
                if (i == ans.size() - 1 and l != n)
                {
                    ans[i].second = n;
                }
                cout << ans[i].first << " " << ans[i].second << endl;
            }
        }
    }
    else
    {
        cout << n << endl;
        for (int i = 0; i < n; i++)
        {
            cout << i + 1 << " " << i + 1 << endl;
        }
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
