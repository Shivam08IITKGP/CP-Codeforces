#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define b begin
#define e end
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

void solve()
{
    int n;
	cin >> n;
	ll a[n];
	set<ll> s;

	ll maxelement = INT_MIN;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
		maxelement = max(a[i], maxelement);
		s.insert(a[i]);
	}

	if (n == 1)
	{
		cout << 1 << endl;
		return;
	}

	ll x = 0;
	for (int i = 0; i < n; ++i)
		x = __gcd(x, maxelement - a[i]);

	ll num = maxelement;
	while (s.find(num) != s.end())
	{
		num -= x;
	}

	ll count = (maxelement - num) / x;
	for (int i = 0; i < n; ++i)
		count += (maxelement - a[i]) / x;
	cout << count << endl;
}
int main()
{
    FASTIO;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
