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
#define ps2 push_back
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define endl '\n'

void solve() {
  string a, b;
  cin >> a >> b;
  int n = a.size(), m = b.size();

  vll ps1(n + 1, 0), ps2(m + 1, 0);

  rep(i, 0, n) 
    ps1[i + 1] = (ps1[i] + (a[i] - '0')) % 10;
  
  rep(i, 0, m) 
    ps2[i + 1] = (ps2[i] + (b[i] - '0')) % 10;

  if (ps1[n] != ps2[m]) {
    pf(-1);
    return;
  }

  vll dp(m + 1, -1), mx(m + 1, -1);

  dp[0] = 0;

  rep(i, 1, n + 1) {
    ll cm = -1;
    rep(y, 0, m + 1) cm = max(cm, dp[y]), mx[y] = cm;

    rep(j, 1, m + 1) 
      if (ps2[j] == ps1[i]) {
      if (j == m && i != n) continue;
      if (mx[j - 1] != -1) dp[j] = max(dp[j], mx[j - 1] + 1);
      }
    }
  
  pf(dp[m]);
}

int main() {
  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}