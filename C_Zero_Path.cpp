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

void solve() {
  int n, m;
  cin >> n >> m;

  vvi a(n, vi(m));

  for (auto& row : a) {
    for (auto& x : row) cin >> x;
  }

  if ((n + m - 1) & 1) {
    cout << "NO" << endl;
    return;
  }

  vvi mn(n, vi(m)), mx(n, vi(m));

  mn[0][0] = mx[0][0] = a[0][0];

  for (int j = 1; j < m; j++) {
    mn[0][j] = mn[0][j - 1] + a[0][j];
    mx[0][j] = mx[0][j - 1] + a[0][j];
  }

  for (int i = 1; i < n; i++) {
    mn[i][0] = mn[i - 1][0] + a[i][0];
    mx[i][0] = mx[i - 1][0] + a[i][0];
  }

  for (int i = 1; i < n; i++) {
    for (int j = 1; j < m; j++) {
      mn[i][j] = a[i][j] + min(mn[i - 1][j], mn[i][j - 1]);
      mx[i][j] = a[i][j] + max(mx[i - 1][j], mx[i][j - 1]);
    }
  }

  if (mn[n - 1][m - 1] <= 0 && 0 <= mx[n - 1][m - 1])
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