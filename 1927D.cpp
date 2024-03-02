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
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<int> p(n);
    p[0] = -1;
    for (int i = 1; i < n; i++)
    {
        (a[i] == a[i - 1]) ? p[i] = p[i - 1] : p[i] = i - 1;
    }
    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        if(l<=p[r])
        {
            cout<<p[r]+1<<" "<<r+1<<endl;
        }
        else
        {
            cout<<-1<<" "<<-1<<endl;
        }
    }
    cout<<endl;
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
