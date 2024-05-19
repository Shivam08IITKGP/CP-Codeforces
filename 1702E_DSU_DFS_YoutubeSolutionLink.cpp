#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define f(i, start, end) for (ll i = start; i < end; i++)
#define fr(i, start, end) for (ll i = start; i > end; i--)
#define vll vector<ll>
#define pll pair<ll, ll>
#define vi vector<int>
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long int ll;

map<int,vi>m;
vi used;

int go(int u)
{
    used[u]=1;
    for(auto child: m[u])
    {
        if(!used[child])
        {
            return 1+go(child);
        }
    }
    return 1;
}

void solve()
{
    int n;
    cin>>n;
    used.assign(n+1,0);
    m.clear();
    bool fault= false;
    f(i,0,n)
    {
        int x,y;
        cin>>x>>y;
        m[x].push_back(y);                         
        m[y].push_back(x);
        if(m[x].size()>2 or m[y].size()>2 or x==y)
        {
            fault= true;
        }

    }
    if(fault)
    {
        cout<<"NO\n";
        return;
    }
  // Strategy is to keep the alternate dominoes in different sets.
  // If there is a cycle then there is no problem, we can divide the edges into two sets
  // If the graph forms cycle then the size of the cycle should be even
  
    f(i,0,n)
    {
        if(!used[i+1])
        {
          // If the length of the cycle is odd
          // Then it is not possible to separate the dominos into two disjoint sets
          // Explanation - https://youtu.be/QXf6QEYcY6c?si=8U7QXDUEHa0A4Mkg&t=504
            if(go(i+1)%2)
            {
                cout<<"NO\n";
                return;
            }
        }
    }
    cout<<"YES\n";
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
