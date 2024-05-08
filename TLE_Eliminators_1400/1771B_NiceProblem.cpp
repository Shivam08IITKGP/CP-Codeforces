#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define iloop(i,k,n) for(int i=k;i<n;i++)
#define dloop(i,n,k) for(int i=n;i>=k;i--)
#define dsort(v) sort(v.begin(),v.end())
#define all(v) v.begin(),v.end()
#define pb push_back
#define pq(v) priority_queue<v>
#define minpq(v) priority_queue<v,vector<v>,greater<v>>
#define ff first
#define ss second
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> pbds;
const int N=1e9+7;
int add_mul(int a,int b) {return ((a%N+b%N)%N+N)%N;}
void input(vector<int>&v,int n) {iloop(i,0,n){int x; cin>>x;v.pb(x);}}
void print(vector<int>v){for(auto x:v) cout<<x<<' '; cout<<endl;}

void solve()
{
    int n,m;
    cin>>n>>m;
    vector<set<int>>sv(n+1);
  //set because it is said that pairs can be repeated
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        int a=max(x,y),b=min(x,y);
        sv[a].insert(b);
    }    
    int ans=0,j=0;

    for(int i=1;i<=n;i++)
    {
        if(sv[i].empty()) ans+=i-j;
        else
        {
            auto it=*(--sv[i].end());
            j=max(it,j);
            ans+=i-j;
        }
    }   
    cout<<ans<<endl;
}

int32_t main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
