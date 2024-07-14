#include <bits/stdc++.h>
using namespace std;

#define int long long

class FenwickTree {
public:
    vector<map<int, int>> b;
    int n;
    FenwickTree(int n) {
        this->n = n + 1;
        b.assign(n + 1, map<int, int>());
    }

    void add(int r, int a) {
        for (; r < n; r += r & -r) {
            b[r][a]++;
        }
    }

    void remove(int r, int a) {
        for (; r < n; r += r & -r) {
            b[r][a]--;
            if (b[r][a] == 0) {
                b[r].erase(a);
            }
        }
    }

    int sum(int r, int a) {
        int ret = 0;
        for (; r > 0; r -= r & -r) {
            if (b[r].find(a) != b[r].end()) {
                ret += b[r][a];
            }
        }
        return ret;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<tuple<int, int, int>> queries(n);
    set<int> times, values;
    
    for (int i = 0; i < n; i++) {
        int a, t, x;
        cin >> a >> t >> x;
        queries[i] = make_tuple(a, t, x);
        times.insert(t);
        values.insert(x);
    }
    
    // Coordinate compression
    unordered_map<int, int> time_map, value_map;
    int time_idx = 1, value_idx = 1;
    
    for (int t : times) {
        time_map[t] = time_idx++;
    }
    for (int x : values) {
        value_map[x] = value_idx++;
    }
    
    FenwickTree f(time_idx); // Using the size after compression
    
    for (auto &[a, t, x] : queries) {
        int compressed_t = time_map[t];
        int compressed_x = value_map[x];
        if (a == 1) {
            f.add(compressed_t, compressed_x);
        } else if (a == 2) {
            f.remove(compressed_t, compressed_x);
        } else if (a == 3) {
            cout << f.sum(compressed_t, compressed_x) << endl;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}
