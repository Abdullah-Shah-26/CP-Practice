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

const int MAXN = 200005;
const int LOG = 20;

vi adj[MAXN];
int up[MAXN][LOG];
int depth[MAXN];

void dfs(int u, int p, int d) {
  depth[u] = d;
  up[u][0] = p;  // assigning immediate parent

  rep(i, 1, LOG) { up[u][i] = up[up[u][i - 1]][i - 1]; }

  for (int v : adj[u]) {
    if (v != p) {
      dfs(v, u, d + 1);
    }
  }
}

int kthAncestor(int u, int k) {
  for (int j = 0; j < LOG; j++) {
    if (k & (1 << j)) u = up[u][j];
  }
  return u;
}

int LCA(int u, int v) {
  if (depth[u] < depth[v]) swap(u, v);

  u = kthAncestor(u, depth[u] - depth[v]);

  if (u == v) return u;

  per(i, LOG, 0) {
    if (up[u][i] != up[v][i]) {
      u = up[u][i];
      v = up[v][i];
    }
  }

  return up[u][0];
}

int dist(int u, int v) { return depth[u] + depth[v] - 2 * depth[LCA(u, v)]; }

void solve() {
  int k;
  cin >> k;

  vi nodes(k);
  rv(nodes);

  // Finding diameter end points
  int src = nodes[0];

  int A = src;
  int mx = -1;

  for (int x : nodes) {
    int d = dist(A, x);
    if (d > mx) {
      mx = d;
      A = x;
    }
  }

  int B = A;
  mx = -1;

  for (int x : nodes) {
    int d = dist(A, x);
    if (d > mx) {
      mx = d;
      B = x;
    }
  }

  for (int x : nodes) {
    if (dist(A, x) + dist(x, B) != dist(A, B)) {
      NO;
      return;
    }
  }
  YES;
}

int main() {
  int n;
  cin >> n;

  rep(i, 0, n - 1) {
    int u, v;
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }

  dfs(1, 1, 0);

  int q;
  cin >> q;

  while (q--) {
    solve();
  }

  return 0;
}