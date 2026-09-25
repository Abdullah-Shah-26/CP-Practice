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
  int n;
  cin >> n;

  vll a(n);
  rv(a);

  int cnt0 = count(all(a), 0);

  if (cnt0 == n) {
    for (int i = 1; i <= n; i++) cout << i << " ";

    cout << endl;
    return;
  }

  int cnt[30] = {};

  for (int x : a) {
    for (int b = 0; b < 30; b++) {
      if (x & (1 << b)) {
        cnt[b]++;
      }
    }
  }

  int g = 0;  // gcd(0, x) = x

  for (int b = 0; b < 30; b++) {
    if (cnt[b]) {
      g = gcd(g, cnt[b]);
    }
  }

  vi ans;

  for (int d = 1; d * d <= g; d++) {
    if (g % d == 0) {
      ans.pb(d);

      if (d != g / d) {
        ans.pb(g / d);
      }
    }
  }

  sort(all(ans));

  for (int x : ans) cout << x << " ";

  cout << endl;
}

int main() {
  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}