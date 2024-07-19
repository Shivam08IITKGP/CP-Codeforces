/*
Consider a book with 5 chapters where:
Chapter 1 has no prerequisites.
Chapter 2 depends on Chapter 1.
Chapter 3 depends on Chapters 1 and 2.
Chapter 4 depends on Chapter 2.
Chapter 5 depends on Chapter 3.
In the first pass, you can immediately understand Chapter 1.
In the second pass, understanding of Chapter 1 allows you to understand Chapter 2.
In the third pass, understanding of both Chapters 1 and 2 allows you to understand Chapter 3, and understanding Chapter 2 alone lets you understand Chapter 4.
In the fourth pass, understanding Chapter 3 now allows Chapter 5 to be understood.


You can think of it as calculating the max depth of the tree

Set s contains those nodes which can be read now as their prerequisites are complete

Lower bound works in set, don't know how but they work.
Simulated internet for a long time but not found any good logic.

*/

#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    vector<int> deg(n);
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      while (x--) {
        int j;
        cin >> j;
        --j;
        g[j].push_back(i);
        deg[i] += 1;
      }
    }
    set<int> s;
    for (int i = 0; i < n; i++) {
      if (deg[i] == 0) {
        s.insert(i);
      }
    }
    int last = -1;
    int ans = 1;
    for (int iter = 0; iter < n; iter++) {
      if (s.empty()) {
        ans = -1;
        break;
      }
      auto it = s.lower_bound(last);
      if (it == s.end()) {
        ans += 1;
        it = s.begin();
      }
      int i = *it;
      s.erase(it);
      for (int j : g[i]) {
        --deg[j];
        if (deg[j] == 0) {
          s.insert(j);
        }
      }
      last = i;
    }
    cout << ans << '\n';
  }
  return 0;
}
