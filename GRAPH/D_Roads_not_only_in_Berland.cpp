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
#define rm(mat)         \
  for (auto& r : (mat)) \
    for (auto& x : (r)) cin >> x
#define pm(mat)                                   \
  do {                                            \
    for (const auto& r : (mat)) {                 \
      for (const auto& x : (r)) cout << x << ' '; \
      cout << '\n';                               \
    }                                             \
  } while (0)
#define pf(x) cout << x << '\n'
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define pb push_back
#define YES cout << "Yes\n"
#define NO cout << "No\n"
#define yno(a) cout << ((a) ? "Yes\n" : "No\n")
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define endl '\n'

/*
==========================



==========================
*/

class DSU {
 private:
  vector<int> parent;
  vector<int> size;

 public:
  DSU(int n) {
    parent.resize(n + 1);
    size.assign(n + 1, 1);

    for (int i = 1; i <= n; i++) parent[i] = i;
  }

  int find(int node) {
    if (parent[node] == node) return node;

    return parent[node] = find(parent[node]);
  }

  bool unite(int u, int v) {
    u = find(u);
    v = find(v);

    if (u == v) return false;

    if (size[u] < size[v]) swap(u, v);

    parent[v] = u;
    size[u] += size[v];

    return true;
  }

  bool same(int u, int v) { return find(u) == find(v); }

  int compSz(int node) { return size[find(node)]; }

  int leader(int node) { return find(node); }
};

void solve() {
  int n;
  cin >> n;

  DSU dsu(n);

  vpii extra, build;

  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;

    // Already connected, This is extra edgee
    if (dsu.find(u) == dsu.find(v)) {
      extra.pb({u, v});
    } else {
      dsu.unite(u, v);
    }
  }

  for (int i = 2; i <= n; i++) {
    if (dsu.find(1) != dsu.find(i)) {
      build.pb({1, i});
      dsu.unite(1, i);
    }
  }

  cout << extra.size() << endl;

  for (int i = 0; i < extra.size(); i++) {
    auto [u, v] = extra[i];  // To remove
    auto [x, y] = build[i];  // To add

    cout << u << ' ' << v << ' ' << x << ' ' << y << endl;
  }
}

int main() {
  int t = 1;
  // cin >> t;

  while (t--) {
    solve();
  }
  return 0;
}