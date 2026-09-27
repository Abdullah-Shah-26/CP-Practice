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

Kosaraju 

==========================
*/

void dfs1(int u, vvi& adj, vi& vis, vi& order) {
  vis[u] = 1;

  for (int v : adj[u]) {
    if (!vis[v]) dfs1(v, adj, vis, order);
  }

  order.pb(u);
}

void dfs2(int u, vvi& adj, vi& comp, int id) {
  comp[u] = id;

  for (int v : adj[u]) {
    if (comp[v] == -1) {
      dfs2(v, adj, comp, id);
    }
  }
}

void solve() {
  int n, m, s;
  cin >> n >> m >> s;

  s--;

  vvi adj(n), radj(n);

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;

    u--;
    v--;

    adj[u].pb(v);
    radj[v].pb(u);
  }

  vi order;
  vi vis(n, 0);

  for (int i = 0; i < n; i++) {
    if (!vis[i]) dfs1(i, adj, vis, order);
  }

  reverse(all(order));

  vi comp(n, -1);
  int sccCnt = 0;

  for (auto u : order) {
    if (comp[u] == -1) {
      dfs2(u, radj, comp, sccCnt);
      sccCnt++;
    }
  }

  // Building DAG of SCC
  // Incoming edges in this SCC from another SCC
  vi indeg(sccCnt, 0);

  for (int u = 0; u < n; u++) {
    for (int v : adj[u]) {
      // There is an incoming edge from u -> v
      // And they are in differnt SCC's

      if (comp[u] != comp[v]) {
        indeg[comp[v]]++;
      }
    }
  }

  // SCC reachable from capital
  vi reachable(n, 0);

  function<void(int)> dfs = [&](int u) {
    reachable[u] = 1;

    for (int v : adj[u]) {
      if (!reachable[v]) {
        dfs(v);
      }
    }
  };

  dfs(s);

  // Mark components that are unreachable from s 
  vi used(sccCnt, 0);

  for (int i = 0; i < n; i++)
    if (!reachable[i]) used[comp[i]] = 1;

  int ans = 0;

  for (int id = 0; id < sccCnt; id++)
    // If the SCC has no incoming edge from other SCC 
    // And if the SCC is not reachable from s 
    // Then we need an edge here 

    if (used[id] && indeg[id] == 0) ans++;

  cout << ans << endl;
}

int main() {
  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}