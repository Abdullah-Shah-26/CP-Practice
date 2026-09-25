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

class DSU {
 private:
  vector<int> parent;
  vector<int> size;

 public:
  DSU(int n) {
    parent.resize(n);
    size.assign(n, 1);

    for (int i = 0; i < n; i++) parent[i] = i;
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
  int n, m;
  cin >> n >> m;

  DSU dsu(n);

  for (int i = 0; i < m; i++) {
    int k;
    cin >> k;

    if (k > 0) {
      int first;
      cin >> first;
      first--;

      for (int j = 1; j < k; j++) {
        int a;
        cin >> a;
        a--;

        dsu.unite(first, a);
      }
    }
  }

  for (int i = 0; i < n; i++) cout << dsu.compSz(i) << ' ';
}

int main() {
  solve();
  return 0;
}