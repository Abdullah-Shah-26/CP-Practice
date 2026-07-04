#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

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
Observation / Thinking
--------------------------



==========================
*/

int row[4] = {-1, 1, 0, 0};
int col[4] = {0, 0, -1, 1};

void solve() {
  int n;
  cin >> n;

  vpii pts(n);
  set<pii> ptset;

  for (int i = 0; i < n; i++) {
    cin >> pts[i].first >> pts[i].second;
    ptset.insert(pts[i]);
  }

  queue<pii> q;
  map<pii, pii> ans;

  for (auto [x, y] : ptset) {
    for (int k = 0; k < 4; k++) {
      int nx = x + row[k];
      int ny = y + col[k];

      if (ptset.find({nx, ny}) == ptset.end()) {
        q.push({x, y});

        // ans[P] = missing_neighbor;
        ans[{x, y}] = {nx, ny};
        
        break;  // Need only 1 valid exit to start
      }
    }
  }

  while (!q.empty()) {
    auto u = q.front();
    auto [x, y] = u;
    q.pop();

    for (int k = 0; k < 4; k++) {
      int nx = x + row[k];
      int ny = y + col[k];

      pii v = {nx, ny};

      if (ptset.find(v) != ptset.end() && ans.find(v) == ans.end()) {
        q.push(v);
        ans[v] = ans[u];
      }
    }
  }

  for (int i = 0; i < n; i++) {
    cout << ans[pts[i]].first << " " << ans[pts[i]].second << endl;
  }
}

int main() {
  int t = 1;
  // cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}