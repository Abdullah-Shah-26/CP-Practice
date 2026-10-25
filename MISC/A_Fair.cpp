#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, k, s;
  cin >> n >> m >> k >> s;

  vector<int> type(n);

  for (int i = 0; i < n; i++) {
    cin >> type[i];
    type[i]--;  // make types 0-based
  }

  vector<vector<int>> adj(n);

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;

    --u;
    --v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  // dist[t][u] = distance from town u
  // to the nearest town producing type t
  vector<vector<int>> dist(k, vector<int>(n));

  for (int t = 0; t < k; t++) {
    // Multi-source BFS for this type.
    queue<int> q;

    for (int u = 0; u < n; u++) {
      if (type[u] == t) {
        dist[t][u] = 0;
        q.push(u);
      } else {
        dist[t][u] = -1;
      }
    }

    while (!q.empty()) {
      int u = q.front();
      q.pop();

      for (int v : adj[u]) {
        if (dist[t][v] != -1) {
          continue;
        }

        dist[t][v] = dist[t][u] + 1;
        q.push(v);
      }
    }
  }

  // Calculate answer for every town.
  for (int u = 0; u < n; u++) {
    vector<int> costs;

    // Cost of obtaining each type at town u.
    for (int t = 0; t < k; t++)
      costs.push_back(dist[t][u]);

    // We need the cheapest s different types.
    sort(costs.begin(), costs.end());

    ll answer = 0;

    for (int i = 0; i < s; i++) {
      answer += costs[i];
    }

    cout << answer << ' ';
  }

  cout << '\n';

  return 0;
}