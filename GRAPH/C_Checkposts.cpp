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

Kosaraju Algorithm : 

==========================
*/

void dfs1(int u, vvi& adj, vb& vis, vi& order) {
  vis[u] = 1;

  for (int v : adj[u]) {
    if (!vis[v]) {
      dfs1(v, adj, vis, order);
    }
  }

  order.pb(u);
}

// Resets for every SCC 
int mn, cnt;

void dfs2(int u, vvi& adj, vb& vis, vi& a) {
  vis[u] = 1;

  // Finding the vertex with min Cost in this SCC
  if (a[u] < mn) {
    mn = a[u];
    cnt = 1;
  }
  // Cnt of vertices having min cost in this SCC
  else if (a[u] == mn) {
    cnt++;
  }

  for (int v : adj[u]) {
    if (!vis[v]) dfs2(v, adj, vis, a);
  }
}

void solve() {
  int n;
  cin >> n;

  vi a(n);
  rv(a);

  int m;
  cin >> m;

  vvi adj(n);
  vvi radj(n);

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;

    u--;
    v--;

    adj[u].pb(v);
    radj[v].pb(u);
  }

  vi order;
  vb vis(n, false);

  for (int i = 0; i < n; i++) {
    if (!vis[i]) dfs1(i, adj, vis, order);
  }

  reverse(all(order));

  fill(all(vis), false);

  ll ways = 1;
  ll totalCost = 0;

  for (int u : order) {
    // Start of new SCC
    // Need vertex with min cost
    // Need cnt of vertices with that min cost
    if (!vis[u]) {
      mn = INF;
      cnt = 0;

      dfs2(u, radj, vis, a);

      totalCost += mn;
      ways = (ways * cnt) % MOD;
    }
  }

  cout << totalCost << " " << ways << endl;
  return;
}

int main() {
  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}