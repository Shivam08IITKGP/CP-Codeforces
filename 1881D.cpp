#include <bits/stdc++.h>
using namespace std;

#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long int ll;

int n;
vector<int> a;
unordered_map<int, int> mp;
void prime_factors(int m)
{
    for (int i = 2; i*i <= m; i++)
    {
        if (m % i == 0)
        {
            while (m % i == 0)
            {
                mp[i]++;
                m /= i;
            }
        }
    }
    if (m > 1)
    {
        mp[m]++;
    }
}
void solve()
{
    cin >> n;
    a.resize(n);
    mp.clear();
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] != 1)
            prime_factors(a[i]);
    }

    for (auto it : mp)
    {
        if (it.second % n != 0)
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    return;
}
int main()
{
    FAST;
    int t;
    cin >> t;
    while (t--)
    {
        mp.clear();
        solve();
    }
    return 0;
}
