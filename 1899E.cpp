#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long int ll;

void solve()
{
    int n;
    cin>>n;
    vector<int>a(n);
    int min_index= 0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        min_index = (a[i]<a[min_index])?i:min_index;        
    }
    for(int i=min_index+1;i<n;i++)
    {
        if(a[i]<a[i-1])
        {
            cout<<-1<<endl;
            return;
        }
    }
    cout<<min_index<<endl;
    return;   
    
}
int main()
{
    FAST;
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
