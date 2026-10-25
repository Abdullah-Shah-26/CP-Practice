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

struct DSU {
  vi parent, sz;

  DSU(int n) {
    parent.resize(n);
    sz.assign(n, 1);

    iota(all(parent), 0);
  }

  int find(int x) {
    if (x == parent[x]) return x;

    return parent[x] = find(parent[x]);
  }

  bool unite(int a, int b) {
    a = find(a);
    b = find(b);

    // Same ultimate parent
    // No merge happened
    if (a == b) return false;

    if (sz[a] < sz[b]) swap(a, b);

    parent[b] = a;
    sz[a] += sz[b];

    // Merge happened
    return true;
  }
};

struct Edge {
  int u, v, w, id;
};

void solve() {
  int n, m;
  cin >> n >> m;

  vector<Edge> edges(m);

  for (int i = 0; i < m; i++) {
    cin >> edges[i].u >> edges[i].v >> edges[i].w;

    --edges[i].u;
    --edges[i].v;

    edges[i].id = i;
  }

  sort(all(edges), [](const Edge& a, const Edge& b) { return a.w < b.w; });

  vs ans(m, "none");
  DSU dsu(n);

  int i = 0;

  while (i < m) {
    int j = i;

    // Group all edges with the same weight
    while (j < m && edges[j].w == edges[i].w) {
      j++;
    }

    // Temporary graph of DSU components
    vvpii adj(n);
    vi candEdges;

    for (int k = i; k < j; k++) {
      int u = edges[k].u;
      int v = edges[k].v;

      int ru = dsu.find(u);
      int rv = dsu.find(v);

      // Already connected using smaller-weight edges
      if (ru == rv) {
        ans[edges[k].id] = "none";
        continue;
      }

      // Can be used in some MST
      ans[edges[k].id] = "at least one";

      int idx = candEdges.size();
      candEdges.pb(edges[k].id);

      adj[ru].pb({rv, idx});
      adj[rv].pb({ru, idx});
    }

    vi tin(n, -1);
    vi low(n, -1);

    int timer = 0;

    function<void(int, int)> dfs = [&](int u, int pId) {
      tin[u] = low[u] = timer++;

      for (auto [v, eId] : adj[u]) {
        if (eId == pId) continue;

        if (tin[v] != -1) {
          // Back edge
          low[u] = min(low[u], tin[v]);
        } else {
          // Tree edge
          dfs(v, eId);

          low[u] = min(low[u], low[v]);

          // Bridge => mandatory in every MST
          if (low[v] > tin[u]) {
            int originalEdgeId = candEdges[eId];
            ans[originalEdgeId] = "any";
          }
        }
      }
    };

    // Find bridges in temporary graph
    for (int k = i; k < j; k++) {
      int u = dsu.find(edges[k].u);

      if (tin[u] == -1) {
        dfs(u, -1);
      }
    }

    // NOW merge this weight group
    for (int k = i; k < j; k++) {
      dsu.unite(edges[k].u, edges[k].v);
    }

    i = j;
  }

  for (string& s : ans) {
    cout << s << endl;
  }
}

int main() {
  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}