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
#define pf(x) cout << x << '\n'
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
  int n, q;
  cin >> n >> q;

  vll a(n);
  rv(a);

  vll mx, sum;

  ll curMax = 0, curSum = 0;

  for (auto x : a) {
    curSum += x;
    curMax = max(curMax, x);

    if (mx.empty() || mx.back() != curMax) {
      mx.pb(curMax);
      sum.pb(curSum);
    } else {
      sum.back() = curSum;
    }
  }

  while (q--) {
    ll k;
    cin >> k;

    auto it = upper_bound(all(mx), k);

    if (it == mx.begin()) {
      cout << 0 << " ";
    } else {
      int pos = it - mx.begin() - 1;
      cout << sum[pos] << " ";
    }
  }

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