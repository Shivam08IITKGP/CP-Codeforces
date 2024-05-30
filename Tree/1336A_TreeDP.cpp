#include "bits/stdc++.h"
using namespace std;

#define rep(i, a, b) for (auto i{a}; i < (b); ++i)
#define per(i, a, b) for (auto i{b}; i-- > (a); )
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

template <class T> bool uin(T& a, const T& b) { return a > b ? a = b, true : false; }
template <class T> bool uax(T& a, const T& b) { return a < b ? a = b, true : false; }

using ll = long long;

ll solve() {
	int n, k;
	cin >> n >> k;

	vector<vector<int>> g(n);
	rep(e, 0, n - 1) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	vector<int> dep(n), sub(n);
	auto dfs = [&](const auto& self, int u, int p) -> void {
		sub[u] = 1;
		for (auto v : g[u]) {
			if (v == p)
				continue;
			dep[v] = dep[u] + 1;
			self(self, v, u);
			sub[u] += sub[v];
		}
	};
	dep[0] = 1;
	dfs(dfs, 0, -1);

	vector<ll> vals(n);
	rep(u, 0, n) vals[u] = dep[u] - sub[u];
	
    // dep[u] is the maximum tourists city found if start from u
    // sub[u] is the number of nodes in the children of u 
    // that earlier had u has one of its tourist cities
    // if we include u then this number must be subtracted from them
	// for (auto x : vals)
	// 	cout << x << ' ';
	// cout << '\n';
	sort(rall(vals));    
	return accumulate(vals.begin(), vals.begin() + k, 0ll);
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);

	cout << solve() << '\n';
}
