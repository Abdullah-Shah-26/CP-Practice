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

ll binExpo(ll a, ll b) {
  ll ans = 1;

  while (b) {
    if (b & 1) ans = ans * a % MOD;

    a = a * a % MOD;
    b >>= 1;
  }

  return ans;
}

void solve() {
  ll n;
  cin >> n;

  ll k;
  cin >> k;

  // 2^(n-1)
  ll half = binExpo(2, n - 1);

  if (n & 1) {
    // Odd : n
    // Ans : (2 ^ (n - 1) + 1) ^ k
    cout << binExpo((half + 1) % MOD, k) << endl;
  } else {
    // 0 bits, xor = 0, and = 0, and >= xor, 1 valid way
    ll ans = 1;  // dp[0]
    ll all = 1;  // (2^n)^0

    ll totalCols = binExpo(2, n);

    for (int i = 1; i <= k; i++) {
      // dp[i] = (2^(n-1) - 1) * dp[i - 1] + (2^n)^(i-1)
      ans = ((half - 1) * ans + all) % MOD;
      all = (all * totalCols) % MOD;
    }

    cout << ans << endl;
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}