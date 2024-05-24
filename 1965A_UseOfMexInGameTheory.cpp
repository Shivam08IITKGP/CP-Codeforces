#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define f(i, start, end) for (ll i = start; i < end; i++)
#define fr(i, start, end) for (ll i = start; i > end; i--)
#define vll vector<ll>
#define pll pair<ll, ll>
#define vi vector<int>
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long int ll;

void solve()
{
    int n;
    cin >> n;
    set<int> s;
    f(i, 0, n)
    {
        int x;
        cin >> x;
        s.insert(x);
    }
    vector<int> v(s.begin(), s.end());
    n= v.size();
    sort(v.begin(), v.end());
    int a = v.back();
    int b=-1;
    f(i,0,v.size())
    {
        if(v[i]!=i+1)
        {
            b=i+1;
            break;
        }
    }
    if(b==-1)
    {
        b= a+1;
    }

    if(b>a)
    {
        cout<<(a%2? "Alice\n":"Bob\n");
    }
    else
    {
        cout<<(b%2? "Alice\n":"Bob\n");
    }
}

int main()
{
    FAST;
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
