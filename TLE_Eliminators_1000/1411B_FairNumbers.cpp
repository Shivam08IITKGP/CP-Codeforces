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

//One by one check every number by increasing it by one
//as max to max we will increase it to lcm(1,2,3,4...,9)=2520 times only.

//There is a shorter algo possible also.
//Take LCM of first k digits and check if there is multiple of lcm greater than n without changing the first k digits.
// However it is complex.
void solve()
{
    ll n;
    cin >> n;
    while (true)
    {
        string s = to_string(n);
        bool flag = false;
        for (int i = 0; i < s.size(); i++)
        {
            ll d = s[i] - '0';
            if (d != 0 && n % d != 0)
            {
                flag = true;
                break;
            }
        }
        if (flag)
        {
            n++;
        }
        else
        {
            cout << n << endl;
            break;
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
