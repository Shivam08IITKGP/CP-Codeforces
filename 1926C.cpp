#include <bits/stdc++.h>
using namespace std;
 
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long int ll;
 
int res[1000000];
int sumofdigits(int n)
{
    int sum = 0;
    int temp = n;
    while (temp)
    {
        sum += temp % 10;
        temp /= 10;
    }
    return sum + res[n - 1];
}
void solve()
{
    int n;
    cin >> n;
    cout << res[n] << endl;
}
int main()
{
    FAST;
    for (int i = 1; i <= 1000000; i++)
    {
        res[i] = sumofdigits(i);
        if (i == 1)
            res[i] = 1;
    }
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
