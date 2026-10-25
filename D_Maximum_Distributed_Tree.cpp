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

vvi adj;
vll wts;  // For each edge u-v, stores s * (n - s)

int dfs(int u, int p, int n) {
  // Size of entire subtree u
  int sz = 1;

  for (int v : adj[u]) {
    if (v != p) {
      // Subtree sizes of child
      int s = dfs(v, u, n);
      wts.pb(1LL * s * (n - s));
      sz += s;
    }
  }

  return sz;
}

void solve() {
  int n;
  cin >> n;

  adj.assign(n + 1, {});

  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].pb(v);
    adj[v].pb(u);
  }

  wts.clear();

  dfs(1, -1, n);

  sort(all(wts));

  int m;
  cin >> m;

  vll f;

  // If we have fewer than n - 1 primes, we insert additional 1's to make up
  while ((int)f.size() < n - 1 - m) f.pb(1);

  for (int i = 0; i < m; i++) {
    ll x;
    cin >> x;
    f.pb(x);
  }

  sort(all(f));

  // If we have more than n - 1 primes, merge largest ones repeatedly
  while ((int)f.size() > n - 1) {
    ll x = f.back();
    f.pop_back();
    f.back() = (f.back() * x) % MOD;
  }

  ll ans = 0;
  for (int i = 0; i < n - 1; i++) {
    ans = (ans + (wts[i] % MOD) * (f[i] % MOD)) % MOD;
  }

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