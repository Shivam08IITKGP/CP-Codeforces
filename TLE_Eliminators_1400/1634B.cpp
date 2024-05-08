#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define f(i, start, end) for (ll i = start; i < end; i++)
#define fr(i, start, end) for (ll i = start; i > end; i--)
#define vll vector<ll>
#define pll pair<ll, ll>
#define vi vector<int>
#define v vector
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long int ll;

/*
a^b and a+b have the same parity after operation. If even is operated with even, result is even. If odd 
is operated with even ,result is odd. odd with odd-> even.

Hence if the summation of a is even , then parity of result and starting number will be same 
else different.
*/
void solve()
{
    ll n, x, y;
    cin >> n >> x >> y;
    ll sum = 0;
    ll ele;
    f(i, 0, n)
    {
        cin >> ele;
        sum += ele;
    }
    if(sum&1)
    {
        if(x%2!=y%2)
        {
            cout<<"Alice\n";
        }
        else
        {
            cout<<"Bob\n";
        }
    }
    else 
    {
        if(x%2!=y%2)
        {
            cout<<"Bob\n";
        }
        else
        {
            cout<<"Alice\n";
        }
    }
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
