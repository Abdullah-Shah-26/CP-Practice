#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

void solve() {
  int n, m, k;
  cin >> n >> m >> k;

  vector<string> grid(n);
  for (auto &s : grid)
    cin >> s;

  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;

  --x1;
  --y1;
  --x2;
  --y2;

  vector<vector<int>> dist(n, vector<int>(m, -1));

  vector<set<int>> row(n);
  vector<set<int>> col(m);

  // IMPORTANT:
  // Store ALL cells, including '#'.
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      row[i].insert(j);
      col[j].insert(i);
    }
  }

  queue<pii> q;

  dist[x1][y1] = 0;
  q.push({x1, y1});

  // Starting cell is visited.
  row[x1].erase(y1);
  col[y1].erase(x1);

  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();

    if (x == x2 && y == y2) {
      cout << dist[x][y] << '\n';
      return;
    }

    // =========================
    // RIGHT
    // =========================

    auto it = row[x].lower_bound(y + 1);

    while (it != row[x].end()) {
      int ny = *it;

      if (ny > y + k)
        break;

      // Wall blocks everything beyond it.
      if (grid[x][ny] == '#')
        break;

      dist[x][ny] = dist[x][y] + 1;
      q.push({x, ny});

      col[ny].erase(x);
      it = row[x].erase(it);
    }

    // =========================
    // LEFT
    // =========================

    it = row[x].lower_bound(y);

    while (it != row[x].begin()) {
      --it;

      int ny = *it;

      if (ny < y - k)
        break;

      // Wall blocks everything beyond it.
      if (grid[x][ny] == '#')
        break;

      dist[x][ny] = dist[x][y] + 1;
      q.push({x, ny});

      col[ny].erase(x);
      it = row[x].erase(it);
    }

    // =========================
    // DOWN
    // =========================

    it = col[y].lower_bound(x + 1);

    while (it != col[y].end()) {
      int nx = *it;

      if (nx > x + k)
        break;

      if (grid[nx][y] == '#')
        break;

      dist[nx][y] = dist[x][y] + 1;
      q.push({nx, y});

      row[nx].erase(y);
      it = col[y].erase(it);
    }

    // =========================
    // UP
    // =========================

    it = col[y].lower_bound(x);

    while (it != col[y].begin()) {
      --it;

      int nx = *it;

      if (nx < x - k)
        break;

      if (grid[nx][y] == '#')
        break;

      dist[nx][y] = dist[x][y] + 1;
      q.push({nx, y});

      row[nx].erase(y);
      it = col[y].erase(it);
    }
  }

  cout << -1 << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
}