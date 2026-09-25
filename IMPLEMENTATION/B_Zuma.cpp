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

const int N = 505;

int n;
int a[N], dp[N][N];

int f(int i, int j) {
  if (i > j) return 0;

  if (i == j) return 1;

  int ans = 1 + f(i + 1, j);

  if(a[i] == a[i + 1])
    ans = min(ans, 1 + f(i + 2, j));

  for(int k = i + 2; k <= j; k++){
    if(a[i] == a[k]){
      ans = min(ans, f(i + 1, k - 1) + f(k + 1, j));
    }
  }

  return ans;
}

void solve() {
  cin >> n;

  for (int i = 0; i < n; i++) cin >> a[i];

  for (int len = 1; len <= n; len++) {
    for (int i = 0; len + i - 1 < n; i++) {
      
      // len = j - i + 1
      // j = len + i - 1

      int j = len + i - 1;

      if (len == 1)
        dp[i][j] = 1;
      else {
        dp[i][j] = dp[i + 1][j] + 1;

        if (a[i] == a[i + 1]) dp[i][j] = min(dp[i][j], 1 + dp[i + 2][j]);

        for (int k = i + 2; k <= j; k++) {
          if (a[i] == a[k]) {
            dp[i][j] = min(dp[i][j], dp[i + 1][k - 1] + dp[k + 1][j]);
          }
        }
      }
    }
  }

  cout << dp[0][n - 1] << endl;
}

int main() {
  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}