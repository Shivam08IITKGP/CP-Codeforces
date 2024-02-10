#include <bits/stdc++.h>
using namespace std;
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long int ll;

void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll ans= 0;
    map<int, int> cnt;
  //map is very good way to calculate nC2
  //So the answer is summation of countofsameNumberC2 + Ones*Twos
  
	for (int i = 0; i < n; i++) {
		ans += cnt[a[i]];
		if (a[i] == 1) ans += cnt[2];
		else if (a[i] == 2) ans += cnt[1];
		cnt[a[i]]++;
	}
    cout<<ans<<endl;
}

int main()
{
    FAST;
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
  //Solution 
  /*
  The problem requires to count the number of pairs of indices (i,j)
 (i<j
) such that (2a)(2b)=(2b)(2a)
, where a=bi,b=bj
. Obviously, when a=b
 this equality is satisfied. Let a≠b
, then rewrite the equality: (2a)(2b)=(2b)(2a)⇔2(a⋅2b)=2(b⋅2a)⇔a⋅2b=b⋅2a⇔ab=2a2b
. Obviously, a
 and b
 must differ by powers of two, otherwise the equality cannot be satisfied, since the ratio of powers of two is on the right. Without loss of generality, suppose that b=a⋅2k
 (k>0
), then the equation takes the form aa⋅2k=2a2a⋅2k⇔12k=12(2k−1)a⇔2k=2(2k−1)a
. If k=1
, then a=1
, b=2
. If k>1
, then 2k−1>k
, and so the equality cannot be satisfied.

Thus, the only possible cases where the equality is satisfied are if bi=bj
 or bi=1,bj=2
 (and vice versa). The number of such pairs can be counted for O(nlogn)
.
 */
