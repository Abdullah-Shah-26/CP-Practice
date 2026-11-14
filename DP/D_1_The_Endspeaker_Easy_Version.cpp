
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

int n, m;
vll a, b, pref;
vvll dp;

ll f(int i, int k) {
  if (i == n + 1) return 0;

  if (dp[i][k] != -1) return dp[i][k];

  ll ans = LINF;

  // Option 1: Increase k.
  if (k < m) {
    ans = min(ans, f(i, k + 1));
  }

  // Option 2: Remove the longest valid prefix.
  // Subarray sum [i...j] = pref[j] - pref[i - 1].

  int j = upper_bound(pref.begin() + i, pref.end(), pref[i - 1] + b[k]) -
          pref.begin() - 1;

  if (j >= i) {
    ans = min(ans, (ll)(m - k) + f(j + 1, k));
  }

  return dp[i][k] = ans;
}

void solve() {
  cin >> n >> m;

  a.resize(n + 1);
  b.resize(m + 1);
  pref.assign(n + 1, 0);

  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= m; i++) cin >> b[i];

  // pref[i] = a[1] + a[2] + ... + a[i].
  for (int i = 1; i <= n; i++) {
    pref[i] = pref[i - 1] + a[i];
  }

  dp.assign(n + 2, vll(m + 2, -1));

  ll ans = f(1, 1);

  if (ans >= LINF) ans = -1;

  cout << ans << endl;
}

int main() {
  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
