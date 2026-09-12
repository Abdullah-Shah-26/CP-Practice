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

void solve() {
  int n;
  cin >> n;
  vi a(n);
  rv(a);

  vi diff(n + 1, 0);
  for (int k = 1; k <= n; k++) {
    ll L = 1LL * a[k - 1] * k;
    ll R = 1LL * (a[k - 1] + 1) * k;
    if (L >= n) continue;
    R = min(R, (ll)n);
    if (L < R) {
      diff[L]++;
      diff[R]--;
    }
  }

  vi ans;
  int cur = 0;
  for (int y = 0; y < n; y++) {
    cur += diff[y];
    if (cur == 0) ans.pb(y);
  }

  cout << ans.size() << '\n';
  for (int x : ans) cout << x << ' ';
  cout << '\n';
}

int main() {
  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}