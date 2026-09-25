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

ll binExpo(ll a, ll b) {
  ll ans = 1;

  while (b) {
    if (b & 1) ans = ans * a % MOD;

    a = a * a % MOD;
    b >>= 1;
  }

  return ans;
}

vvi adj;
vi vis;
int sz;

void dfs(int x) {
  vis[x] = 1;
  sz++;  // count vertex in current red component
  for (auto& i : adj[x]) {
    if (!vis[i]) dfs(i);  // explore only through red edges
  }
}

void solve() {
  int n, k;
  cin >> n >> k;

  adj.assign(n + 1, {});

  for (int i = 0; i < n - 1; i++) {
    int u, v, x;
    cin >> u >> v >> x;

    if (x == 0) {
      adj[u].pb(v);
      adj[v].pb(u);
    }
  }

  int ans = 0;
  vis.assign(n + 1, 0);

  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      sz = 0;
      dfs(i);
      ans = (ans + binExpo(sz, k)) % MOD;
    }
  }

  ans = (binExpo(n, k) - ans + MOD) % MOD;
  pf(ans);
}

int main() {
  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}