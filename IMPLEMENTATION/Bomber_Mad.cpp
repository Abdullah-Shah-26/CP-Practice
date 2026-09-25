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
const ll LINF = 1e18;
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
#define pf(x) cout << x << '\n'
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

int row[4] = {-1, 1, 0, 0};
int col[4] = {0, 0, -1, 1};

void solve() {
  ll h, w, k;
  cin >> h >> w >> k;

  vector<vector<char>> grid(h, vector<char>(w, '.'));
  vb r(h), c(w);  // r,c has bomb

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> grid[i][j];

      if (grid[i][j] == '#') {
        r[i] = true;
        c[j] = true;
      }
    }
  }

  queue<pii> q;
  vvi dist(h, vi(w, -1));

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (grid[i][j] == '.' && !r[i] && !c[j]) {
        q.push({i, j});
        dist[i][j] = 0;
      }
    }
  }

  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();

    for (int k = 0; k < 4; k++) {
      int nx = x + row[k];
      int ny = y + col[k];

      if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;

      if (grid[nx][ny] == '#') continue;

      if (dist[nx][ny] != -1) continue;

      dist[nx][ny] = dist[x][y] + 1;
      q.push({nx, ny});
    }
  }

  ll ans = 0;

  rep(i, 0, h) {
    rep(j, 0, w) {
      if (grid[i][j] == '.' && dist[i][j] != -1 && dist[i][j] <= k) ans++;
    }
  }

  cout << ans << endl;
}

int main() {
  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}