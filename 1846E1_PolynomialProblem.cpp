#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define f(i, start, end) for (ll i = start; i < end; i++)
#define fr(i, start, end) for (ll i = start; i > end; i--)
#define vll vector<ll>
#define pll pair<ll, ll>
#define vi vector<int>
#define v vector
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long int ll;

set<ll>nums;

void solve()
{
    int n;
    cin>>n;
    //check if n is of the form 1 + x + x^2 + x^3 + .....+ x^k or not 
    //To do this precalculate all such value possible upto k=20 and n<=1e6

    if(nums.count(n)) cout<<"YES\n";
    else cout<<"NO\n";
    
}

int main()
{
    FAST;

    f(i,2,1001)
    {
        ll val= 1+i;
        ll p= i*i;
        f(j,2,21)
        {
            val+=p;
            if(val>=1e6)
            {
                break;
            }
            nums.insert(val);
            p*=i;
        }
    }
    // for(auto it:nums)
    // {
    //     cout<<it<<" ";
    // }
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
