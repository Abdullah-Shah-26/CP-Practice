#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
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
#define eb emplace_back
#define rs resize
#define as assign
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define yno(a) cout << ((a) ? "YES\n" : "NO\n")
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define per(i, a, b) for (int i = (b) - 1; i >= (a); --i)
#define endl '\n'

/*
====================== DATA STRUCTURES ======================
DSU: dsu | Fenwick: fenwick | SegTree: segtree | LazySeg: lazyseg
NodeSeg: nodeseg | SparseTable: sparse | CoordCompress: compress
PrefixSum: prefix | PrefixSum2D: prefix2d
DiffArr: diffarr | DiffArr2D: diff2d
MonoStack: monost | MonoQueue: monoq
InversionCount: invcnt | LIS: lis

=========================== TREES ===========================
BinaryLifting(LCA): lca
EulerTour: euler
HLD: hld

========================== GRAPHS ============================
DFS: dfs | BFS: bfs | 01BFS: 01bfs
Dijkstra: dijkstra | BellmanFord: bellman | FloydWarshall: floyd
Kruskal: kruskal | Prim: prim
Topo(Kahn): topo | Topo(DFS): topodfs
Kosaraju: kos | Tarjan: tarjan
Bridge: bridge | ArticulationPoint: ap
Bipartite: bipartite
Cycle(Undirected): cycle | Cycle(Directed): cycledir

========================== STRINGS ===========================
KMP: kmp | Z: zalgo | Manacher: manacher
RollingHash: rhash | Trie: trie | BinaryTrie: btrie

============================ MATH ============================
BinExpo: binexpo
Combinatorics: comb
Sieve: sieve | LinearSieve: lsieve | SPF: spf
Divisors: div
MatrixExpo: matexpo
ExtendedGCD: egcd

============================= DP ============================
DPReference: dpref
LIS: lis
EditDistance: edit
*/

const int MAXN = 200005;

int n, q;
vi adj[MAXN];
int lights[MAXN];
int euler[MAXN];
int in[MAXN];
int out[MAXN];
int timer = 0;
int seg[4 * MAXN];
int lazy[4 * MAXN];

void dfs(int u) {
  in[u] = timer;
  euler[timer] = lights[u];
  timer++;

  for (int v : adj[u]) dfs(v);

  out[u] = timer - 1;
}

void build(int i, int l, int r) {
  if (l == r) {
    seg[i] = euler[l];
    return;
  }

  int mid = (l + r) >> 1;
  build(2 * i + 1, l, mid);
  build(2 * i + 2, mid + 1, r);

  seg[i] = seg[2 * i + 1] + seg[2 * i + 2];
}

void push(int i, int l, int r) {
  if (l == r) return;

  if (lazy[i]) {
    int mid = (l + r) >> 1;

    // Toggling light bulb
    // If on make it off
    // If off make it on
    // We store cnt of on
    // Then cnt of off = (N) - cnt of on
    // N = Range = mid-l+1
    //   = r - mid

    seg[2 * i + 1] = (mid - l + 1) - seg[2 * i + 1];
    lazy[2 * i + 1] = !lazy[2 * i + 1];

    seg[2 * i + 2] = (r - mid) - seg[2 * i + 2];
    lazy[2 * i + 2] = !lazy[2 * i + 2];

    lazy[i] = false;
  }
}

void updateRange(int i, int l, int r, int ql, int qr) {
  if (l > qr || r < ql) return;

  if (l >= ql && r <= qr) {
    seg[i] = (r - l + 1) - seg[i];
    lazy[i] = !lazy[i];
    return;
  }

  // Before going deep
  // Propogate changes to children

  push(i, l, r);
  int mid = (l + r) >> 1;
  updateRange(2 * i + 1, l, mid, ql, qr);
  updateRange(2 * i + 2, mid + 1, r, ql, qr);

  seg[i] = seg[2 * i + 1] + seg[2 * i + 2];
}

int queryRange(int i, int l, int r, int ql, int qr) {
  if (l > qr || r < ql) return 0;

  if (l >= ql && r <= qr) {
    return seg[i];
  }

  push(i, l, r);

  int mid = (l + r) >> 1;
  int lans = queryRange(2 * i + 1, l, mid, ql, qr);
  int rans = queryRange(2 * i + 2, mid + 1, r, ql, qr);

  return lans + rans;
}

void solve() {
  cin >> n;

  for (int v = 2; v <= n; v++) {
    int u;
    cin >> u;
    adj[u].pb(v);
  }

  rep(i, 1, n + 1) { cin >> lights[i]; }

  dfs(1);  // flattening using euler

  build(0, 0, n - 1);

  cin >> q;
  while (q--) {
    string t;
    int v;

    cin >> t >> v;

    if (t == "pow") {
      updateRange(0, 0, n - 1, in[v], out[v]);
    } else if (t == "get") {
      cout << queryRange(0, 0, n - 1, in[v], out[v]) << endl;
    }
  }
}

int main() {
  solve();
  return 0;
}