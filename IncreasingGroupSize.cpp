#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    int t1=INT_MAX,t2=INT_MAX;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(t1>t2)
        {
            swap(t1,t2);
        }
        //less than the smaller of the last two elements
        //case - 1
        if(a[i]<=t1)
        {
            t1=a[i];
        }
        //middle of the two elements
        //case - 3 
        else if(a[i]<=t2)
        {
            t2=a[i];
        }
        //greater than both the elements
        //case - 2
        else
        {
            t1= a[i];
            ans++;
        }
        //Intuitively see this solution
        //if you are finding an element that is greater than both the elements
        //Then you must have to increase the penalty        
    }
    cout<<ans<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
