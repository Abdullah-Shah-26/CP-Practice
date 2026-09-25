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

#define rv(s) \
  for (auto& x : (s)) cin >> x
#define pv(s)                                   \
  do {                                          \
    for (const auto& x : (s)) cout << x << ' '; \
    cout << '\n';                               \
  } while (0)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define pb push_back
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define rep(i, s, b) for (int i = (s); i < (b); ++i)
#define endl '\n'

/*
==========================



==========================
*/

const int N = 505;

int n;
int dp[N][N];
string s;

int f(int l, int r) {
  if (l > r) return 0;

  if (dp[l][r] != -1) return dp[l][r];

  int ans = 1 + f(l + 1, r);

  for (int k = l + 1; k <= r; k++) {
    if (s[l] == s[k]) {
      ans = min(ans, f(l + 1, k - 1) + f(k, r));
    }
  }

  return dp[l][r] = ans;
}

void solve() {
  cin >> n;
  cin >> s;

  memset(dp, -1, sizeof(dp));

  cout << f(0, n - 1) << endl;
}

int main() {
  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}