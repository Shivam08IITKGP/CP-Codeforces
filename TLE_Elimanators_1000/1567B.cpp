#include <bits/stdc++.h>
using namespace std;

#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long int ll;

void solve()
{
    int a, b;
    cin >> a >> b;
    int ans = a;
    int xor_ = 0;
    int test;

    if (a % 4 == 1) {xor_ = a - 1;}
    else if (a % 4 == 2) {xor_ = 1;}
    else if (a % 4 == 3) {xor_ = a;}
    else {xor_ = 0;}
    test = xor_ ^ b;

    if (xor_ == b)    
        cout << ans << endl;    
    else if ((test != a))    
        cout << ans + 1 << endl;    
    else    
        cout << ans + 2 << endl;
    
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
