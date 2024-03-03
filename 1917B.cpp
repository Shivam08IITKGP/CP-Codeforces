#include<bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long int ll;

void solve();
int main()
{
    FAST;
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}
//Approach is go from i=0 to n
//If you find a first occurence of any letter, 
//than apply second operations as many number of times,
//You will always get a new string

//Lets apply i1 first operations and j1 second operations. 
//(i1,j1) is same as (i2,j2) if i1+j1=i2+j2 and a[i1]=a[i2] (Possibly)

//If after applying first operations x times and the first letter is not the first occurence,
//then any string obtained by applying the second operation on this string can also be obtained
//by applying second operation on that string which has this strings first letter as first occurence.
void solve()
{
    int n;
    cin>>n;
    string a;
    cin>>a;
    vector<int>first_occurences(26,-1);
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(first_occurences[a[i]-'a']==-1)
        {
            first_occurences[a[i]-'a']=1;
            ans+=(n-i);
        }
    }
    cout<<ans<<endl;
}
