#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

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
#define eb emplace_back
#define rs resize
#define as assign
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define yno(a) cout << ((a) ? "YES\n" : "NO\n")
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define per(i, a, b) for (int i = (b) - 1; i >= (a); --i)
#define endl '\n'

void solve() {
  ll n;
  cin >> n;

  string s;
  cin >> s;

  vll x(n + 1), y(n);

  for (int i = 1; i <= n; i++) cin >> x[i];
  for (int j = 1; j <= n - 1; j++) cin >> y[j];

  // 0 - r
  // 1 - s
  // dp[i][0] = maxH after first i days, dayi = r
  // dp[i][1] = maxH after first i days, dayi = s

  vvll dp(n + 1, vll(2, -LINF));

  dp[1][0] = (s[0] == 'R') ? 0 : -x[1];
  dp[1][1] = (s[0] == 'S') ? 0 : -x[1];

  for (int i = 2; i <= n; i++) {
    ll costR = (s[i - 1] == 'R') ? 0 : x[i];
    ll costS = (s[i - 1] == 'S') ? 0 : x[i];

    // cur = R
    dp[i][0] = max(dp[i][0], dp[i - 1][0] - costR);
    dp[i][0] = max(dp[i][0], dp[i - 1][1] - costR);

    // cur = S
    dp[i][1] = max(dp[i][1], dp[i - 1][1] - costS);
    dp[i][1] = max(dp[i][1], dp[i - 1][0] - costS + y[i - 1]);
  }

  cout << max(dp[n][0], dp[n][1]) << endl;
}

int main() {
  int t;
  cin >> t;
  while(t--)
  solve();
  return 0;
}