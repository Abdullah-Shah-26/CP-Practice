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

// nodes, edges, limits

==========================
*/

using T = tuple<int, int, int>;

struct DSU {
  vi parent, sz;

  DSU(int n) {
    parent.resize(n + 1);
    sz.assign(n + 1, 1);
    iota(begin(parent), end(parent), 0);
  }

  int find(int x) {
    if (x == parent[x]) return x;

    return parent[x] = find(parent[x]);
  }

  bool unite(int u, int v) {
    u = find(u);
    v = find(v);

    // Already in same component
    // Dont merge
    if (u == v) return false;

    if (sz[u] < sz[v]) swap(u, v);

    parent[v] = u;
    sz[u] += sz[v];

    return true;
  }
};

void solve() {
  int n, m;
  ll k;

  cin >> n >> m >> k;

  vector<T> edges(m);

  for (auto& [u, v, w] : edges) {
    cin >> u >> v >> w;
  }

  // Sorting edges by wt
  sort(all(edges),
       [](const auto& a, const auto& b) { return get<2>(a) < get<2>(b); });

  DSU dsu(n);
  ll ans = 0;

  for (auto [u, v, w] : edges) {
    if (w < k) dsu.unite(u, v);
  }

  ll minCost = LINF;
  bool used = false;

  // Max edge wt in MST must be exactly = k
  for (auto [u, v, w] : edges) {
    minCost = min(minCost, abs((ll)w - k));

    if (w >= k && dsu.unite(u, v)) {
      ans += (w - k);
      used = true;
    }
  }

  if (!used) ans = minCost;

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