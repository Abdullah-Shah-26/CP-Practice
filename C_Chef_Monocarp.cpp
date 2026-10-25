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

int f(int i, int t, vi& a, vvi& dp) {
  if (i == a.size()) return 0;

  if (t > 2 * a.size()) return INF;

  int& ans = dp[i][t];

  if (ans != -1) return ans;

  // Take the dish out at minute t
  int take = abs(a[i] - t) + f(i + 1, t + 1, a, dp);

  // Dont take any dish out at time t
  int skip = f(i, t + 1, a, dp);

  return ans = min(take, skip);
}

void solve() {
  int n;
  cin >> n;

  vi a(n);
  rv(a);

  sort(all(a));

  vvi dp(n, vi(2 * n + 2, -1));

  cout << f(0, 1, a, dp) << endl;
}

int main() {
  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}