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
    if (n == 1)
    {
        cout << 2 << endl;
        return;
    }
    int l = 1, r = 2;

    int curr;
    for (int i = 0; i < n; i++)
    {
        if (i == 0 and a[0] == '<')
        {
            curr = r;
            continue;
        }
        else if (i == 0 and a[0] == '>')
        {
            curr = l;
            continue;
        }
        if (a[i] == '<')
        {
            if (curr == r)
            {
                r++;
            }
            curr++;
        }
        else
        {
            if (curr == l)
            {
                l--;
            }
            curr--;
        }
    }

    cout << r - l + 1 << endl;
    // Fails when the string is >><>>

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
