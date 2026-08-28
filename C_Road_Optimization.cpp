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

int n, l;
ll dist[502];
ll a[502];
ll dp[502][502];

ll f(int i, int k) {
  if (i >= n) return 0;

  if (dp[i][k] != -1) return dp[i][k];

  ll ans = LINF;
  for (int remove = 0; remove <= k; remove++) {
    if (i + remove >= n) break;
    ll cost = (dist[i + remove + 1] - dist[i]) * a[i];
    ans = min(ans, cost + f(i + remove + 1, k - remove));
  }

  return dp[i][k] = ans;
}

void solve() {
  int k;
  cin >> n >> l >> k;

  memset(dp, -1, sizeof(dp));

  for (int i = 0; i < n; i++) cin >> dist[i];

  dist[n] = l;

  for (int i = 0; i < n; i++) cin >> a[i];

  cout << f(0, k) << "\n";
}

int main() {
  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}