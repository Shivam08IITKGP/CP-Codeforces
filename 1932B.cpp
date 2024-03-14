#include <bits/stdc++.h>
using namespace std;

#define FAST                 \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
typedef long long int ll;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;

    sort(a.begin(),a.end());
  //if the first two elements are equal then we need to search for an element a[i] 
  // that we will put in the front of the vector. a[i]%a[0] will be the smallest integer now.
  
    if(a[0]==a[1])
    {
        for(int i=2;i<n;i++)
        {
            if(a[i]%a[0]!=0)
            {
                cout<<"YES"<<endl;
                return;
            }
        }
        cout<<"NO"<<endl;
    }
      // if only one smallest element then answer is always yes
    else
    {
        cout<<"YES"<<endl;
    }



    
    return;
}
int main()
{
    FAST int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
