#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  vector<int> d(n);
  int mx = 0, start = -1;

  vector<vector<int>> levels(n);

  for (int i = 0; i < n; i++) {
    cin >> d[i];

    levels[d[i]].push_back(i);
    mx = max(mx, d[i]);

    if (d[i] == 0) {
      if (start != -1) {
        cout << -1 << '\n';
        return 0;
      }

      start = i;
    }
  }

  if (levels[0].size() != 1) {
    cout << -1 << '\n';
    return 0;
  }

  vector<int> degree(n, 0);
  vector<pair<int, int>> ans;

  for (int i = 1; i <= mx; i++) {
    if (levels[i - 1].empty()) {
      cout << -1 << '\n';
      return 0;
    }

    set<pair<int, int>> st;

    for (int v : levels[i - 1]) {
      st.insert({degree[v], v});
    }

    for (int u : levels[i]) {
      auto [deg, v] = *st.begin();

      if (deg == k) {
        cout << -1 << '\n';
        return 0;
      }

      st.erase(st.begin());

      ans.push_back({u, v});

      degree[u]++;
      degree[v]++;

      st.insert({degree[v], v});
    }
  }

  cout << ans.size() << '\n';

  for (auto [u, v] : ans) {
    cout << u + 1 << ' ' << v + 1 << '\n';
  }

  return 0;
}