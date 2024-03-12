#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        // We first start with ceil m/k coins
        // Then we take m%k coins

        // Now we start replacing 1 coin of denomination k with k coins of denomination 1
        // We will apply this operation on only the left needed coins of denomination k

        int m, k, a1, ak;
        cin >> m >> k >> a1 >> ak;
        int Start_k = m / k;
        int Start_1 = m % k;

        int coin_1_required_more = max(0, Start_1 - a1);
        //if coin1 required more is 0 then coin1 left is not 0
        // else if coin1 required more is not 0 then coin1 left is 0

        int coin_1_left = max(0, a1 - Start_1);

        int coin_k_required_more = max(0, Start_k - ak);

        int replace = min(coin_1_left / k, coin_k_required_more);

        int ans = coin_1_required_more + coin_k_required_more - replace;

        //Test Case
        // m= 11 k = 3 a1 = 6 ak = 1
        // Start_k = 3
        // Start_1 = 2
        // coin_1_required_more = 0
        // coin_1_left = 4
        // coin_k_required_more = 2
        // coin1 left/k = 4/3 = 1
        // replace = 1
        // ans= 0 + 2- 1= 1

        // Actually we will use 2 coins of denomination 3 and 5 coins of denomination 1
        // 2*3 + 5*1 = 11      


        cout << ans << endl;
    }
}
