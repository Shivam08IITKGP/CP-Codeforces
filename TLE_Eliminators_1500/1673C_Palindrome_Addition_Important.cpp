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
ll MOD = 1e9 + 7;
ll N = 40004, M = 502;
vector<vector<ll>> dp(N,vector<ll>(M));
vector<int> palindromes;

bool is_a_palindrome(int i)
{
    string t = to_string(i);
    string s = t;
    reverse(t.begin(), t.end());
    return s == t;
}

void solve()
{
    palindromes.push_back(0);
    for (int i = 1; i < 2 * N; i++)
    {
        if (is_a_palindrome(i))
        {
            palindromes.push_back(i);
        }
    }
    for (int j = 1; j < M; j++)
    {
        dp[0][j] = 1;
    }
    for (int i = 1; i < N; i++)
    {
        dp[i][0] = 0;
        for (int j = 1; j < M; j++)
        {
            if (palindromes[j] <= i)
            {
                dp[i][j] = (dp[i][j - 1] + dp[i - palindromes[j]][j]) % MOD;
            }
            else
            {
                dp[i][j] = dp[i][j - 1];
            }
        }
    }
}
ll getanswer(int n)
{
    return dp[n][M - 1];
}

int main()
{
    FAST;
    int t;
    cin >> t;
    solve();
    while (t--)
    {
        int n;
        cin >> n;
        cout << getanswer(n) << endl;
    }
}
