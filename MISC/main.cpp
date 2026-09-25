#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n;
vector<int> color;
vector<vector<int>> adj;

int total0, total1;
ll originalScore = 0;
ll bestReduction = 0;

pair<int, int> dfs(int u, int parent, int depth) {
  int sub0 = (color[u] == 0);
  int sub1 = (color[u] == 1);

  for (int v : adj[u]) {
    if (v == parent) continue;

    auto [child0, child1] = dfs(v, u, depth + 1);

    sub0 += child0;
    sub1 += child1;
  }

  // Same-color pairs crossing the edge (parent, u).
  ll cross =
      1LL * sub0 * (total0 - sub0) +
      1LL * sub1 * (total1 - sub1);

  if (u != 1) {
    // This edge contributes 'cross' to the original score.
    originalScore += cross;

    // Moving u directly to the root removes depth[u] - 1 edges
    // from every affected pair.
    ll reduction = cross * (depth - 1);

    bestReduction = max(bestReduction, reduction);
  }

  return {sub0, sub1};
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;

  while (T--) {
    cin >> n;

    color.resize(n + 1);
    adj.assign(n + 1, {});

    total0 = total1 = 0;

    for (int u = 1; u <= n; u++) {
      cin >> color[u];

      if (color[u] == 0)
        total0++;
      else
        total1++;
    }

    for (int i = 0; i < n - 1; i++) {
      int u, v;
      cin >> u >> v;

      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    originalScore = 0;
    bestReduction = 0;

    dfs(1, 0, 0);

    cout << originalScore - bestReduction << '\n';
  }
}