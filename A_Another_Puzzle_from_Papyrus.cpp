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
  ll n, c;
  cin >> n >> c;

  vll a(n), b(n);
  rv(a);
  rv(b);

  ll ans = INF;

  bool f = 1;
  ll cost = 0;

  rep(i, 0, n) {
    if (a[i] < b[i]) f = 0;

    cost += (a[i] - b[i]);
  }

  if (f) ans = min(ans, cost);

  sort(all(a));
  sort(all(b));

  cost = c;

  int i = 0, j = 0;

  while (i < n && j < n) {
    while (i < n && b[j] > a[i]) i++;

    if (i == n) break;

    cost += (a[i] - b[j]);
    j++;
    i++;
  }

  if (j == n) ans = min(ans, cost);

  if (ans == INF)
    pf(-1);
  else
    pf(ans);
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}