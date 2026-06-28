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
  int n, q;
  cin >> n >> q;

  vvpii adj(n);
  vi forced(n, -1);

  for (int i = 0; i < q; i++) {
    int u, v, x;
    cin >> u >> v >> x;
    u--, v--;

    if (u == v)
      forced[u] = x;
    else {
      adj[u].pb({v, x});
      adj[v].pb({u, x});
    }
  }

  vi a(n, 0);

  for (int b = 0; b < 30; b++) {
    vi val(n, 1);

    rep(i, 0, n) {
      if (forced[i] != -1) {
        val[i] = (forced[i] >> b) & 1;
      }
    }

    rep(i, 0, n) {
      for (auto [j, x] : adj[i]) {
        if (((x >> b) & 1) == 0) {
          val[i] = 0;
        }
      }
    }

    rep(i, 0, n) {
      if (val[i] == 0 || forced[i] != -1) continue;

      bool ok = true;
      for (auto [j, x] : adj[i]) {
        if (((x >> b) & 1) && (val[j] == 0)) {
          ok = false;
          break;
        }
      }

      if (ok) val[i] = 0;
    }

    rep(i, 0, n) if (val[i]) a[i] |= (1 << b);
  }

  pv(a);
}

int main() {
  solve();
  return 0;
}