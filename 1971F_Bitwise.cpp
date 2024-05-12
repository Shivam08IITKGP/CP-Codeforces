#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define f(i, start, end) for (ll i = start; i < end; i++)
#define fr(i, start, end) for (ll i = start; i > end; i--)
#define vll vector<ll>
#define pll pair<ll, ll>
#define vi vector<int>
#define v vector
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long int ll;

void solve()
{
    int n;
    cin>>n;
    map<int,priority_queue<int>>m;
    vector<int>a(n);
    for(int i=0;i<n;i++)
    {
      // Sorting is possible among those numbers whose all bits are same except the last 2 bits
      // Hence group them together
        cin>>a[i];
        m[a[i]/4].push(-a[i]);
    }
    for(int i=0;i<n;i++)
    {
        cout<<-m[a[i]/4].top()<<" ";
        m[a[i]/4].pop();
    }
    cout<<endl;
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
