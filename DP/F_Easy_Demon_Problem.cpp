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

const int LIM = 200000;
const int SZ = 2 * LIM + 1;
vb hasU(SZ, false), hasV(SZ, false);

void solve() {
  int n, m, q;
  cin >> n >> m >> q;

  vll a(n), b(m);

  ll A = 0, B = 0;

  for (ll& x : a) {
    cin >> x;
    A += x;
  }

  for (ll& x : b) {
    cin >> x;
    B += x;
  }

  for (int i = 0; i < n; i++) {
    ll u = A - a[i];

    if (abs(u) <= LIM) hasU[u + LIM] = true;
  }

  for (int i = 0; i < m; i++) {
    ll v = B - b[i];

    if (abs(v) <= LIM) hasV[v + LIM] = true;
  }

  auto check = [&](ll d, ll e, ll x, bool& ok) {
    if (abs(d) > LIM || abs(e) > LIM) return;

    if (d * e != x) return;

    if (hasU[d + LIM] && hasV[e + LIM]) ok = true;
  };

  while (q--) {
    ll x;
    cin >> x;

    ll ax = abs(x);
    bool ok = false;

    for (ll d = 1; d * d <= ax && !ok; d++) {
      if (ax % d) continue;

      ll e = ax / d;

      check(d, e, x, ok);
      check(e, d, x, ok);
      check(-d, -e, x, ok);
      check(-e, -d, x, ok);
      check(d, -e, x, ok);
      check(-d, e, x, ok);
      check(-e, d, x, ok);
      check(e, -d, x, ok);
    }

    if (ok)
      YES;
    else
      NO;
  }
}

int main() {
  int t = 1;
  
  while (t--) {
    solve();
  }

  return 0;
}