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

void solve() {
  int n, m;
  cin >> n >> m;

  vll a(n + 1);
  for (int i = 1; i <= n; i++) cin >> a[i];

  // a[i] | a[i + 1]
  auto contribution = [&](int i) -> ll {
    if (i < 1 || i >= n) return 0;

    if (a[i] == a[i + 1]) return 0;

    return 1LL * i * (n - i);
  };

  ll ans = 1LL * n * (n + 1) / 2;

  for (int i = 1; i < n; i++) {
    ans += contribution(i);
  }

  while (m--) {
    int i;
    ll x;
    cin >> i >> x;

    ans -= contribution(i - 1);
    ans -= contribution(i);

    a[i] = x;

    ans += contribution(i - 1);
    ans += contribution(i);

    cout << ans << endl;
  }
}

int main() {
  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}