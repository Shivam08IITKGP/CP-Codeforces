#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    long long positive_segments = 0;
    long long negative_segments = 0;

    int even_count = 1;
    int odd_count = 0;

    int negative_count = 0;

    for (int i = 0; i < n; ++i)
    {
        if (a[i] < 0)
        {
            negative_count++;
        }

        if (negative_count % 2 == 0)
        {
            positive_segments += even_count;
            negative_segments += odd_count;
            even_count++;
        }
        else
        {
            positive_segments += odd_count;
            negative_segments += even_count;
            odd_count++;
        }
    }

    cout << negative_segments << " " << positive_segments << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
