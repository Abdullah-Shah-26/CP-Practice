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
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define endl '\n'

/*
==========================



==========================
*/

const int MAXF = 5200;  // 25 fives max per number (5^26 > 1e18) * 200

void solve() {
  int n, k;
  cin >> n >> k;

  vector<int> twos(n, 0), fives(n, 0);
  for (int i = 0; i < n; i++) {
    ll x;
    cin >> x;
    while (x % 2 == 0) {
      twos[i]++;
      x /= 2;
    }
    while (x % 5 == 0) {
      fives[i]++;
      x /= 5;
    }
  }

  vector<vector<int>> dp(k + 1, vector<int>(MAXF + 1, -1));
  dp[0][0] = 0;

  for (int i = 0; i < n; i++) {
    for (int j = min(i + 1, k); j >= 1; j--) {
      for (int f = MAXF; f >= fives[i]; f--) {
        int prev = dp[j - 1][f - fives[i]];

        if (prev >= 0) dp[j][f] = max(dp[j][f], prev + twos[i]);
      }
    }
  }

  int ans = 0;
  for (int f = 0; f <= MAXF; f++) {
    if (dp[k][f] >= 0) ans = max(ans, min(f, dp[k][f]));
  }

  cout << ans << "\n";
}

int main() {
  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}