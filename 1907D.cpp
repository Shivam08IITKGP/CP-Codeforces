#include<bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long int ll;
//I just did Binary Search on the target number
bool satisfy(vector<ll>&l,vector<ll>&r,ll k)
{
    ll n= l.size();
    ll left=0;
    ll right= 0;
    for(int i=0;i<n;i++)
    {
        if(i==0)
        {
            if(l[i]>k) return false;
            left= l[i];
            right= min(r[i],k);
            continue;
        }
        if(l[i]>right+k) return false;
        else if(r[i]<left-k) return false;
        else
        {
            left= max(left-k,l[i]);
            right= min(right+k,r[i]);
        }
        
    }
    return true;
}
void solve()
{
    ll n;
    cin>>n;
    vector<ll>l(n),r(n);
    ll maxi=0;
    
    for(int i=0;i<n;i++)
    {
        cin>>l[i]>>r[i];
        maxi=max(maxi,r[i]);
    }
    ll left= 0;
    ll right=maxi;
    ll mid=(left+right)/2;
    while(1)
    {
        if(satisfy(l,r,mid))
        {
            right=mid;
        }
        else
        {
            left=mid+1;
        }
        mid=(left+right)/2;
        if(left>=right) break;
    }
    cout<<mid<<"\n";
}
int main()
{
    FASTIO
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}
