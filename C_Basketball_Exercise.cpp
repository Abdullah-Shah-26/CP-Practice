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

No 2 consecutive selections can be from same row
Index of present chosen guy should be > past chosen idx
ie same idx can't be chosen

dp1[i] = max ht we can obtain using col 1..i where the last guy is from row 1

dp2[i] = max ht we can obtain using col 1..i where the last guy is from row 2

dp1[i] = max(dp1[i], a[i] + dp2[i - 1])
dp2[i] = max(dp2[i], b[i] + dp1[i - 1])

dp[i] = max total ht using col 1...i

Skip :
dp[i] = dp[i - 1]

Take :
Case 1 : Take from row 1, then last guy must be from row 2
Case 2 : Take from row 2, then last guy must be from row 1

dp[i] = max(dp[i - 1], a[i] + dp2[i - 1], b[i] + dp1[i - 1])

==========================
*/

void solve() {
  int n;
  cin >> n;

  vll a(n), b(n);

  rv(a);
  rv(b);

  vll dp(n), dp1(n), dp2(n);

  dp1[0] = a[0];
  dp2[0] = b[0];
  dp[0] = max(dp1[0], dp2[0]);

  for (int i = 1; i < n; i++) {

    // Skip, Take past from diff row + current from this row
    dp1[i] = max(dp1[i - 1], dp2[i - 1] + a[i]);
    dp2[i] = max(dp2[i - 1], dp1[i - 1] + b[i]);

    dp[i] = max({dp[i - 1], dp1[i], dp2[i]});
  }

  cout << dp[n - 1] << endl;
}

int main() {
  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}