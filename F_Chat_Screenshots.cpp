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

bool dfs(int u, vll& vis, vll& pathvis, vll adj[]) {
  vis[u] = 1;
  pathvis[u] = 1;

  for (auto v : adj[u]) {
    if (!vis[v]) {
      if (dfs(v, vis, pathvis, adj)) {
        return true;
      }
    } else if (pathvis[v])
      return true;
  }

  pathvis[u] = 0;
  return false;
}

void solve() {
  ll n, k;
  cin >> n >> k;

  vvll ss(k, vll(n));

  for (int i = 0; i < k; i++) {
    for (int j = 0; j < n; j++) {
      cin >> ss[i][j];
    }
  }

  vll adj[n + 1];

  for (auto vec : ss) {
    for (int i = 1; i < n - 1; i++) {
      int u = vec[i];
      int v = vec[i + 1];

      if (find(all(adj[u]), v) == adj[u].end()) {
        adj[u].pb(v);
      }
    }
  }

  vll vis(n + 1), pathvis(n + 1);

  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      if (dfs(i, vis, pathvis, adj)) {
        NO;
        return;
      }
    }
  }

  YES;
  return;
}

int main() {
  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}