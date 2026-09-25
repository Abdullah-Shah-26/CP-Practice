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
  int n, m, k;
  cin >> n >> m >> k;

  vll c(n);
  rv(c);

  vector<vector<ll>> bonus(n, vector<ll>(n, 0));

  for (int i = 0; i < k; i++) {
    int x, y;
    ll c;
    cin >> x >> y >> c;

    --x;
    --y;

    bonus[x][y] = c;
  }

  // -1 means unreachable state
  vvll dp(1 << n, vll(n, -1));

  ll ans = 0;

  for (int i = 0; i < n; i++) dp[1 << i][i] = c[i];

  for (int mask = 0; mask < (1 << n); mask++) {
    for (int last = 0; last < n; last++) {
      if (dp[mask][last] == -1) continue;

      for (int nxt = 0; nxt < n; nxt++) {
        if (mask & (1 << nxt)) continue;

        int newMask = mask | (1 << nxt);

        // Satisfaction from eating the dish itself: a[nxt]
        // Extra bonus from the adjacent pair: bonus[last][nxt]
        dp[newMask][nxt] =
            max(dp[newMask][nxt], dp[mask][last] + bonus[last][nxt] + c[nxt]);
      }

      if (__builtin_popcount(mask) == m)
        ans = max(ans, dp[mask][last]);
    }
  }

  cout << ans << endl;
}

int main() {
  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}