#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

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
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
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

ll gcdll(ll a, ll b) {
  while (b) {
    ll t = a % b;
    a = b;
    b = t;
  }
  return a;
}

void solve() {
  ll n;
  cin >> n;

  ll LCM = 9e18;
  ll f = 1, s = n - 1;

  for (ll d = 2; (d * d) <= n; d++) {
    if (n % d == 0) {
      ll a = d;
      ll b = n - d;
      ll lcm = (a * b) / (gcdll(a, b));

      if (lcm < LCM) {
        LCM = lcm;
        f = a;
        s = b;
      }

      ll a1 = n / d;
      ll b1 = n - a1;
      lcm = (a1 * b1) / (gcdll(a1, b1));

      if(lcm < LCM){
        LCM = lcm;
        f = a1;
        s = b1;
      }
    }
  }

  cout << f << " " << s << endl;
  
}

int main() {
  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}