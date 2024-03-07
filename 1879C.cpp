#include <bits/stdc++.h>
using namespace std;

#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long int ll;
const ll mod = 998244353;

ll calculate_nminuskfactorial(int n,int k)
{
    ll ans = 1;
    for (int i = 2; i <= n - k; i++)
    {
        ans = (ans * i) % mod;
    }
    return ans;
}
//The first output is the number of possible alternating sequences that can be generated(n-k)
//The second output is the number of ways to achieve one of the above
//That is the number of ways required to remove repeating chars

//k number of blocks of same characters 
//For the second output first choose which characters will remain after deletions
// that i can choose in (length of a block) number of ways in a block
//Hence pie(lengthofblocks)
// Now we choose the order in which we will remove the remaining characters
//This I can do in (n-k)! ways

void solve()
{
    string a;
    cin >> a;
    int n = a.size();
    ll ans = 1;
    int k = 1;
    int length = 1;
    for (int i = 1; i < n; i++)
    {
        if (a[i] == a[i - 1])
        {
            length++;
        }
        else
        {
            k++;
            ans = (ans * length) % mod;
            length = 1;
        }
    }
    ans = (ans * length) % mod;
    ans = (ans * calculate_nminuskfactorial(n, k)) % mod;
    cout<<n-k<<" "<<ans<<endl;

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
    return 0;
}
