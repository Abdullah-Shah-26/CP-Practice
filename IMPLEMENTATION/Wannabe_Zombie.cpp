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
using T = tuple<ll, ll, ll>;

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
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define pb push_back
#define YES cout << "Yes\n"
#define NO cout << "No\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define endl '\n'

/*
==========================



==========================
*/

void solve() {
  ll n;
  cin >> n;

  vll x(n);
  rv(x);

  if (n == 1) {
    cout << 0 << endl;
    return;
  }

  for (ll k = 0; k < n; k++) {
    ll ans = LINF;

    if (k + 1 < n) {
      ll timeLeft = (x[k + 1] - x[0]) / 2;
      ll timeRight = (x[n - 1] - x[k]) / 2;

      ans = min(ans, max(timeLeft, timeRight));
    }

    if (k - 1 >= 0) {
      ll timeLeft = (x[k] - x[0]) / 2;
      ll timeRight = (x[n - 1] - x[k - 1]) / 2;

      ans = min(ans, max(timeLeft, timeRight));
    }

    cout << ans << endl;
  }
}

int main() {
  int t = 1;
  // cin >> t;

  while (t--) {
    solve();
  }
  return 0;
}