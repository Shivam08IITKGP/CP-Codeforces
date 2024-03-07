#include <bits/stdc++.h>
using namespace std;

#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long int ll;
// 2d vector bana rha hun
// jismein pehla variable length hai aur dusra wala sum hai

// ab main pehle suppose n length ke string mein hun

//(n even hai toh)toh fir main n+2 n+4 .... total length banjaye ,
// isliye us length ke strings search kr rha hun
//(n odd hai toh) n+1 n+3 n+5 etc wale check kr rha hun


//jab main l length ke string par hun aur k length ka check kr rha hun
//See the image of this question 


void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<string> s(n);
    for (int i = 0; i < n; i++)
    {
        s[i] = to_string(a[i]);
    }
    ll ans = 0;
    vector<int> size(n);
    for (int i = 0; i < n; i++)
    {
        size[i] = (int)s[i].size();
    }
    vector<vector<ll>> cnt(6, vector<ll>(46, 0));

    for (int i = 0; i < n; i++)
    {
        int total_sum = 0;
        for (int j = 0; j < size[i]; j++)
        {
            total_sum += s[i][j] - '0';
        }
        for (ll length = size[i] + 2 - size[i] % 2; length <= 10; length += 2)
        {
            if (length > 2 * size[i])
                break;
            // this if is for concatenating a smaller string only than the current string
            int a = 0, b = 0;
            for (ll j = 0; j < size[i] - length / 2; j++)
            {
                a += s[i][j] - '0';
                b += s[i][size[i] - j - 1] - '0';
            }
            // when we are doing these two below lines, we are searching for the
            // strings that are smaller than the current string
            // total_sum -a is positive but total_sum-2*a can be negative also
            // so we are taking max(0, total_sum-2*a)
            ans += cnt[length - size[i]][max(0, total_sum - 2 * a)];
            ans += cnt[length - size[i]][max(0, total_sum - 2 * b)];
        }
        cnt[size[i]][total_sum]++;
        ans++;
    }
    cout << ans << endl;
}
int main()
{
    FAST;
    int t;
    // cin>>t;
    t = 1;
    while (t--)
    {
        solve();
    }
}
