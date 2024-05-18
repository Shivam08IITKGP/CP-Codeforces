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
    vector<int>a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int ans = 1;
    for(int i=0;i<21;i++)
    {
        int prev=-1;
        for(int j=0;j<n;j++)
        {
            if(a[j]&(1<<i))
            {
                ans=max(ans,j-prev);
                prev=j;
            }
        }
        if(prev!=-1)
        {
            ans=max(ans,n-prev);
        }
    }
    cout<<ans<<endl;

    //Time complexity is O(n)
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
