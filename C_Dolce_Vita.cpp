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
  int n, x;
  cin >> n >> x;

  vector<int> cost(n);
  for (int i = 0; i < n; i++) cin >> cost[i];

  sort(cost.begin(), cost.end());

  vector<long long> pref(n);
  pref[0] = cost[0];

  for (int i = 1; i < n; i++) {
    pref[i] = pref[i - 1] + cost[i];
  }

  long long ans = 0;

  for (int i = 0; i < n; i++) {
    if (pref[i] <= x) {
      long long k = i + 1;
      long long days = (x - pref[i]) / k + 1;
      ans += days;
    }
  }

  cout << ans << "\n";
}

int main() {
  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}