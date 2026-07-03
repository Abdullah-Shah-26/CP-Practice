#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// Ordered Set
#define oset                                   \
  tree<int, null_type, less<int>, rb_tree_tag, \
       tree_order_statistics_node_update>
// order_of_key(k) : No of Elements < k
// *find_by_order(i) : Value at idx i (0 - based)

// ---------- Type aliases ----------
using ll = long long;
using ull = unsigned long long;
using ld = long double;
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

// ---------- Constants ----------
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;

// ---------- Fast IO ----------
static const auto fastio = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}();

// ---------- Macros ----------
#define rv(a) \
  for (auto& x : (a)) cin >> x
#define pv(a)                                   \
  do {                                          \
    for (const auto& x : (a)) cout << x << ' '; \
    cout << '\n';                               \
  } while (0)
#define rm(mat)         \
  for (auto& r : (mat)) \
    for (auto& x : (r)) cin >> x
#define pm(mat)                                   \
  do {                                            \
    for (const auto& r : (mat)) {                 \
      for (const auto& x : (r)) cout << x << ' '; \
      cout << '\n';                               \
    }                                             \
  } while (0)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define pb push_back
#define eb emplace_back
#define rs resize
#define as assign
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define yno(a) cout << ((a) ? "YES\n" : "NO\n")
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define per(i, a, b) for (int i = (b) - 1; i >= (a); --i)
#define endl '\n'

int row[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int col[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

// ---------- Solve ---------
void solve() {
  ll n, m;
  cin >> n >> m;

  vector<vector<char>> grid(n, vector<char>(m, '.'));
  vvi dist(n, vi(m, -1));
  queue<pii> q;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> grid[i][j];
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] != '#') continue;

      bool bound = false;
      for (int k = 0; k < 8; k++) {
        int nr = i + row[k];
        int nc = j + col[k];

        if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;

        if (grid[nr][nc] == '.') {
          bound = true;
          break;
        }
      }

      if (bound) {
        dist[i][j] = 0;
        q.push({i, j});
      }
    }
  }

  while (!q.empty()) {
    auto [r, c] = q.front();
    q.pop();

    for (int k = 0; k < 8; k++) {
      int nr = r + row[k];
      int nc = c + col[k];

      if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
        if (dist[nr][nc] == -1) {
          dist[nr][nc] = dist[r][c] + 1;
          q.push({nr, nc});
        }
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (dist[i][j] != -1 && dist[i][j] % 2 == 0)
        cout << '#';
      else
        cout << '.';
    }
    cout << '\n';
  }
}

// ---------- Main ----------
int main() {
  solve();
  return 0;
}