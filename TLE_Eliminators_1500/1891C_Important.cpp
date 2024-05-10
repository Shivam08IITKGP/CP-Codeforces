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

void solve()
{
    ll n;
    cin >> n;
    vll a(n);
    ll sum = 0;
    f(i, 0, n)
    {
        cin >> a[i];
        sum += a[i];
    }
    sort(a.begin(), a.end());
    ll i = 0, j = n - 1;
    ll x = 0;
    ll moves = 0;
    while (i <= j)
    {
        if (a[j] == x)
        {
            x = 0;
            // a[j] = 0;
            moves++;
            j--;
            continue;
        }

        if (i == j)
        {
            if (a[i] == 1)
            {
                moves++;
                i++;
                break;
            }
            ll k = (a[i] - x) / 2;
            if (a[i] - x - 2 * (k) == 1)
                k++; // attack type 1 on left monster
            i++;
            moves += k + 1; //attack type 2 on x monsters initially
            break;
        }

        if (a[i] + x > a[j])
        {
            ll u = a[j] - x;
            x = a[j];
            a[i] -= u;
            moves += u;
        }
        else
        {
            x += a[i];
            moves += a[i];
            // a[i] = 0;

            i++;
        }
    }

    cout << moves << endl;
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
