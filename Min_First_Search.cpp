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
const ll LINF = 4e18;

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
#define YES cout << "Yes\n"
#define NO cout << "No\n"
#define yno(a) cout << ((a) ? "Yes\n" : "No\n")
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define endl '\n'

/*
==========================

==========================
*/

const int MOD = 998244353;

struct Fenwick {
  int n;
  vector<int> bit;

  Fenwick(int n) : n(n), bit(n + 1, 0) {}

  void update(int i, int val) {
    for (; i <= n; i += i & -i) {
      bit[i] = max(bit[i], val);
    }
  }

  int query(int i) {
    int res = 0;

    for (; i > 0; i -= i & -i) {
      res = max(res, bit[i]);
    }

    return res;
  }
};

void solve() {
  int n;
  cin >> n;

  vi q(n + 1);

  for (int i = 1; i <= n; i++) {
    cin >> q[i];
  }

  Fenwick fw(n);

  ll ans = 1;

  for (int i = 1; i <= n; i++) {
    int v = q[i];

    if (i > 1) {
      int rv = n - v + 1;

      // Last position before i having value > v.
      int L = fw.query(rv - 1);

      int choices;

      if (L == 0) {
        choices = i - 1;
      } else {
        choices = i - L;
      }

      ans = ans * choices % MOD;
    }

    int rv = n - v + 1;
    fw.update(rv, i);
  }

  cout << ans << '\n';
}

int main() {

  solve();

  return 0;
}