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
using T = tuple<ll, ll, ll>;

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

int row[4] = {0, 0, -1, 1};
int col[4] = {1, -1, 0, 0};

void solve() {
  int n, m;
  cin >> n >> m;

  vs grid(n);
  for (auto& s : grid) cin >> s;

  int totalG = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] == 'G') totalG++;

      // Block all free cells surrounding 'B'
      if (grid[i][j] == 'B') {
        for (int k = 0; k < 4; k++) {
          int ni = i + row[k];
          int nj = j + col[k];

          if (ni >= 0 && nj >= 0 && ni < n && nj < m) {
            if (grid[ni][nj] == '.') {
              grid[ni][nj] = '#';
            }
          }
        }
      }
    }
  }

  vvb vis(n, vb(m, false));
  queue<pii> q;

  int reachedG = 0;
  bool reachedB = 0;

  // BFS from exit to reach cell G
  if (grid[n - 1][m - 1] != '#') {
    q.push({n - 1, m - 1});
    vis[n - 1][m - 1] = true;
  }

  while (!q.empty()) {
    auto [i, j] = q.front();
    q.pop();

    if (grid[i][j] == 'G') reachedG++;
    if (grid[i][j] == 'B') reachedB = true;

    for (int k = 0; k < 4; k++) {
      int ni = i + row[k];
      int nj = j + col[k];

      if (ni >= 0 && nj >= 0 && ni < n && nj < m) {
        if (vis[ni][nj] || grid[ni][nj] == '#') continue;

        vis[ni][nj] = true;
        q.push({ni, nj});
      }
    }
  }

  if (reachedG == totalG && reachedB == false)
    YES;
  else
    NO;
}

int main() {
  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}