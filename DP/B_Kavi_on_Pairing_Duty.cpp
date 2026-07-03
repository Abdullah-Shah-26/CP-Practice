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
const int MOD = 998244353;

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

int N = 1e6;
vector<int> cnt(N + 1);

void precompute() {
  for (int d = 1; d <= N; d++) {
    for (int multiple = d; multiple <= N; multiple += d) {
      cnt[multiple] = (cnt[multiple] + 1) % MOD;
    }
  }
}

void solve() {
  ll n;
  cin >> n;

  // No of good pairings using i points
  int dp[2 * n + 1];
  dp[0] = 1;

  // Sum of dp[0] + dp[2] + .... + dp[i]
  int pre[2 * n + 1];
  pre[0] = 1;

  // 1st case :
  // 1 -> (n-i) ans = divisors(n) - 1

  // 2nd case :
  // 1 -> (n+i) ans = pre[i-2] = dp[0] + dp[2] + .....

  for (int i = 2; i <= 2 * n; i += 2) {
    dp[i] = pre[i - 2] + (cnt[i / 2] - 1);
    dp[i] %= MOD;

    pre[i] = pre[i - 2] + dp[i];
    pre[i] %= MOD;
  }

  cout << dp[2 * n] << endl;
}

int main() {
  precompute();
  solve();
  return 0;
}