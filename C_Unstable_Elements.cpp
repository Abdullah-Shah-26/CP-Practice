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
#define pb push_back
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define endl '\n'

void solve() {
  ll n, k;
  cin >> n >> k;

  vll a(n);
  rv(a);

  vll c;
  ll cur = 1;

  rep(i, 1, n) {
    if (a[i] == a[i - 1])
      cur++;
    else {
      c.pb(cur);
      cur = 1;
    }
  }

  c.pb(cur);

  sort(all(c));

  ll m = c.size();

  vll suff(m + 1, 0);

  for (int i = m - 1; i >= 0; i--)
    suff[i] = suff[i + 1] + c[i];

  ll ans = 0;
  rep(i, 0, m) {
    ll s = m - i;
    ll w = suff[i];

    if ((k - w) % s == 0) {
      ll delta = (k - w) / s;

      if (c[i] + delta >= 1) {
        if (i > 0 && c[i - 1] == c[i]) continue;

        ans++;
      }
    }
  }

  pf(ans);
}

int main() {
  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}