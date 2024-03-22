#include <bits/stdc++.h>
using namespace std;

#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long int ll;

void solve()
{
    int k, x, initial_total;
    cin >> k >> x >> initial_total;

    // Here the significance of x is that after x loses, Sasha must win the next round


    if (initial_total <= x)
    {
        cout << "NO\n";
        return;
    }
    else if (k > x + 1)
    {
        // Play with only coins of value 1 for x times and win at (x+1)th time
        cout << "YES\n";
        return;
    }

    // if(k<=x+1) then we can't play with only coins of value 1

    else
    {
        int loss = 0;
        x++;
        while (x--)
        {
            // Current_bet is the minimum bet that you can place to recover the loss
            // We are checking if we lose even this bet, then we are bankrupt
            int current_bet = loss / (k - 1) + 1;
            loss += current_bet;
            if (loss > initial_total)
            {
                // Bankrupt
                cout << "NO\n";
                return;
            }
        }
        cout << "YES\n";
        return;
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
