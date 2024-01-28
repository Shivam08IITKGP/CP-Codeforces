#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
void solveFaster()
{
    ll n,x;
    cin>>x>>n;
    ll ans=1;
    if(n==1)
    {
        cout<<x<<endl;
        return;
    } 
    //Calculating factors upto sqrt(x) is much faster than upto x/n
    //as n is always less than x
    
    //This loop is O(sqrt(x))
    //Whereas if you do iterations till x/n
    //It is O(x)
    vector<ll>factors;
    for(int i=1;i<=sqrt(x);i++)
    {
        if(x%i==0)
        {
            if(x/i==i)
            {
                factors.push_back(i);
            }
            else
            {
                factors.push_back(i);
                factors.push_back(x/i);
            }
        }
    }
    
    sort(factors.begin(),factors.end());
    auto it= lower_bound(factors.begin(),factors.end(),n);
    
    cout<< x / *it <<endl;
    return;   
}
void solveSlower()
{
    ll n,x;
    cin>>x>>n;
    ll ans=1;
    if(n==1)
    {
        cout<<x<<endl;
        return;
    }
    if(x%n==0)
    {
        cout<<x/n<<endl;
        return;
    }
    
 
    for(ll i=2;i<=x/n;i++)
    {
        
        if(x%i==0)
        {
            ll temp=x-i*n;
            if(temp%i==0)
            {
                ans=max(ans,i);
            }
        }
    }
    cout<<ans<<endl;
    return;    
}

int main()
{
    FASTIO
    ll t;
    cin>>t;
    while(t--)
    {
        solveFaster();
    }
}
