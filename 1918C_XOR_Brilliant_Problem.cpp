#include <bits/stdc++.h>
using namespace std;
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long int ll;

const int maxb = 60;

void solve()
{
    int64_t a, b, r;
    cin >> a >> b >> r;
    int64_t x = 0;
    if(a>b) swap(a,b);
    bool firstbit = true;
    for (int i = maxb - 1; i >= 0; i--)
    {
        bool bita = a & (1LL << i);
        bool bitb = b & (1LL << i);
        if (bita != bitb)
        {
            if (firstbit)
            {
                firstbit = false;
            }
            else
            {
                if (!bita and x + (1LL << i) <= r)
                {
                    //if the current position at a is 0 and b is 1 
                    //then we can keep there 1 at a's position and 0 at b's position

                    //only check if x+2^i is smaller than r 
                    //ans will be sort of 10000 - 01111
                    //Only the first bit of b is 1 and rest wherever possible 
                    //put 1 in a and 0 in b
                    x += (1ll << i);
                    a ^= (1ll << i);
                    b ^= (1ll << i);
                }
            }
        }
    }
    cout<<b-a<<endl;
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
}
