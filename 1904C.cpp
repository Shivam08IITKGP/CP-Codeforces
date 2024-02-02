#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define FASTIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
#define b begin
#define e end
void solve()
{
	ll n, k;
	cin >> n >> k;
	vector<ll> a(n);
	for (ll i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	if (k >= 3)
	{
		cout << 0 << endl;
		return;
	}
	sort(b(a), e(a));
	ll m = a[0];
	for (int i = 0; i < n - 1; i++)
	{
		m = min(a[i + 1] - a[i], m);
	}
	if (k == 1)
	{
		cout << m << endl;
		return;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			ll diff = a[j] - a[i];
			ll index = lower_bound(b(a), e(a), diff) - b(a);
			if (index < n)
				m = min(m, a[index] - diff);
			if (index > 0)
				m = min(m, diff - a[index - 1]);
			if (m == 0)
			{
				cout << 0 << endl;
				return;
			}
		}
	}
	cout << m << endl;
}
int main()
{
	FASTIO;
	ll t;
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}
//if k==3 then output is always 0
//if k==1 then the min(least difference between two numbers ,numbers themselves)
//if k==2 then the answer is min(least difference between two numbers ,numbers themselves, 
// binary searched difference between difference and its lower bounds)
