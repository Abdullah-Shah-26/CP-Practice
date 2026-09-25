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
  ll n;
  cin >> n;

  vll p1(n), p2(n), p3(n);

  for (int i = 0; i < n; i++) {
    ll x;
    cin >> x;

    if (i > 0) {
      p1[i] = p1[i - 1];
      p2[i] = p2[i - 1];
      p3[i] = p3[i - 1];
    }

    if (x == 1)
      p1[i]++;
    else if (x == 2)
      p2[i]++;
    else if (x == 3)
      p3[i]++;
  }

  vll val(n);

  rep(i, 0, n) val[i] = p1[i] + p2[i] - p3[i];

  vll suffmax(n, -LINF);
  suffmax[n - 2] = val[n - 2];

  for (int i = n - 3; i >= 0; i--) suffmax[i] = max(suffmax[i + 1], val[i]);

  bool f = false;

  for (int i = 0; i <= n - 3; i++) {
    if (p1[i] < p2[i] + p3[i]) continue;

    if (suffmax[i + 1] >= val[i]) {
      f = true;
      break;
    }
  }

  if (f)
    YES;
  else
    NO;
}

int main() {
  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}