// The answer is the 1 + maximum size of the subarray having the same symbol.
// Note: Don't apply the two pointers approach here because
//       We have an example >><>>
//       If we apply the two pointers approach, then we get the answer as 2 1 0 1 0 -1 -> 4
//       but we can get an array 2 1 0 2 1 0 -> 3
//       So, don't try to find the array as you do not know what characters are ahead and the number here 
//       does depend on the succeeding characters.

//       The two-pointer approach (wrong approach) is in another file with the same name.




#include <bits/stdc++.h>
using namespace std;

#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long int ll;

void solve()
{
    int n;
    cin >> n;
    string a;
    cin >> a;
    int curr = 1, ans = 1;
    for(int i=1;i<n;i++)
    {
        if(a[i] == a[i-1])
        {
            curr++;
            ans = max(ans, curr);
        }
        else
        {
            curr = 1;
        }    
    }
    cout << ans + 1<< endl;
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
