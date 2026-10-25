#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using vs = vector<string>;
using vb = vector<bool>;
using vvb = vector<vector<bool>>;
using vpii = vector<pii>;
using vvpii = vector<vector<pii>>;
using vpll = vector<pll>;
using vvpll = vector<vector<pll>>;

const int INF = 1e9;
const ll LINF = 4e18;
const int MOD = 1e9 + 7;

static const auto fastio = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}();

#define rv(a) \
  for (auto& x : (a)) cin >> x
#define pv(a)                                   \
  do {                                          \
    for (const auto& x : (a)) cout << x << ' '; \
    cout << '\n';                               \
  } while (0)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define pb push_back
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define endl '\n'

/*
==========================



==========================
*/

//            R  L  U  D
int row[4] = {0, 0, -1, 1};
int col[4] = {1, -1, 0, 0};

void solve() {
  int n, m;
  cin >> n >> m;

  // Start cell
  int r, c;
  cin >> r >> c;

  r--, c--;

  // No more than x left, or y right
  int x, y;
  cin >> x >> y;

  vector<string> grid(n);

  for (auto& row : grid) cin >> row;

  vvi dist(n, vi(m, INF));
  deque<pii> dq;

  // dist[i][j] = min no of left moves needed to reach (i,j)

  dist[r][c] = 0;
  dq.push_front({r, c});

  while (!dq.empty()) {
    auto [cr, cc] = dq.front();
    dq.pop_front();

    for (int d = 0; d < 4; d++) {
      int nr = cr + row[d];
      int nc = cc + col[d];

      if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;

      if (grid[nr][nc] == '*') continue;

      int cost = (d == 1);  // Cost of left move
      int newd = dist[cr][cc] + cost;

      if (newd < dist[nr][nc]) {
        dist[nr][nc] = newd;

        if (cost == 0)
          dq.push_front({nr, nc});
        else
          dq.push_back({nr, nc});
      }
    }
  }

  int cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (dist[i][j] == INF) continue;

      int leftUsed = dist[i][j];
      int rightUsed = leftUsed + (j - c);

      if (leftUsed <= x && rightUsed <= y) cnt++;
    }
  }

  cout << cnt << endl;
}

int main() {
  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}