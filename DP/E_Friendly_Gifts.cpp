#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

// Ordered Set
#define oset                                   \
  tree<int, null_type, less<int>, rb_tree_tag, \
       tree_order_statistics_node_update>

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
  int n;
  cin >> n;

  vi a(n);
  rv(a);

  vvi dp(n, vi(n, -1));

  for (int i = 0; i < n; i++) {
    dp[i][i] = a[i];

    vi cnt(n + 1);
    cnt[a[i]] = 1;

    int flag = 0, mx = a[i], mn = a[i];

    for (int j = i - 1; j >= 0; j--) {
      if (cnt[a[j]]) flag = 1;  // seen

      if (!flag) {
        mx = max(mx, a[j]);
        mn = min(mn, a[j]);

        if (mx - mn == i - j) dp[j][i] = mx;
        cnt[a[j]] = 1;
      }
    }
  }

  for (int len = n / 2; len > 0; len--) {
    vi firstIdx(n + 1, 1e9);

    for (int i = 0; i <= n - len; i++) {
      int t = dp[i][i + len - 1];

      if (t != -1) {
        if (t - len >= 0 && firstIdx[t - len] <= i - len) {
          cout << len << endl;
          return;
        }

        if (t + len <= n && firstIdx[t + len] <= i - len) {
          cout << len << endl;
          return;
        }

        firstIdx[t] = min(firstIdx[t], i);
      }
    }
  }

  cout << 0 << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}