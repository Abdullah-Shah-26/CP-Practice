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
  ll n, m;
  cin >> n >> m;

  vi a(n + 1), d(n + 1), b(n + 1);
  vi cnt(n + 1, 0);
  vvi e(m + 1);

  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> d[i] >> b[i];

    if (d[i] == 1) {
      cnt[b[i]]++;
    } else {
      cnt[a[i]]++;
      e[d[i]].pb(i);
    }
  }

  int dist = 0;
  for (int c = 1; c <= n; c++) {
    if (cnt[c] > 0) dist++;
  }

  cout << dist << endl;
  for (int i = 2; i <= m; i++) {
    for (int bird : e[i]) {
      int old = a[bird];
      int newc = b[bird];

      cnt[old]--;
      if (cnt[old] == 0) dist--;

      if (cnt[newc] == 0) dist++;
      cnt[newc]++;
    }

    cout << dist << endl;
  }
  cout << endl;
}

int main() {
  solve();
  return 0;
}