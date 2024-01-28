#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
void solve()
{
    ll n,k,m;
    cin>>n>>k>>m;
    string s;
    cin>>s;
    
    set<char>se;
    ll count= 0;
    char curr;
    vector<char>ans;

    for(ll i=0;i<m;i++)
    {
        se.insert(s[i]);
        if(se.size()==k)
        {
            count++;
            se.clear();
            // curr= s[i];
            ans.push_back(s[i]);
        }
    }
    if(count>=n)

    cout<<"YES\n";
    else
    {
        cout<<"NO\n";
        for(ll i=0;i<ans.size();i++)
        {
            cout<<ans[i];
        }
        char last;
        for(ll i=0;i<k;i++)
        {
            if(se.find('a'+i)==se.end())
            {
                last= 'a'+i;
                break;
            }
        }
        for(ll i=ans.size();i<n;i++)
        {
            cout<<last;
        }
        cout<<"\n";

    }
}

int main()
{
    FASTIO
    ll t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}
