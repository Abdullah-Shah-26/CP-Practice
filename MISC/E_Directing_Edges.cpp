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

vi order;
vi used;
vvi adj;

void dfs(int u) {
  used[u] = 1;

  for (int v : adj[u]) {
    if (!used[v]) {
      dfs(v);
    }
  }

  // First push all of its children, then push parent
  // Parent must have higher priority than children
  order.pb(u);
}

void solve() {
  int n, m;
  cin >> n >> m;

  adj = vvi(n);

  vpii edges;

  for (int i = 0; i < m; i++) {
    int t, u, v;
    cin >> t >> u >> v;

    u--, v--;

    // Cannot change direction of these edges
    if (t == 1) {
      adj[u].pb(v);
    }

    edges.pb({u, v});
  }

  order.clear();

  used = vi(n);

  for (int i = 0; i < n; i++) {
    if (!used[i]) dfs(i);
  }

  // Assigning positions / priority
  vi pos(n);
  reverse(begin(order), end(order));

  for (int i = 0; i < n; i++) pos[order[i]] = i;

  bool bad = false;

  for (int u = 0; u < n; u++) {
    // u before v
    // pos[u] must be < pos[v]
    // else the graph already has cycle

    for (auto v : adj[u]) {
      if (pos[u] > pos[v]) {
        bad = true;
        break;
      }
    }

    if (bad) break;
  }

  if (bad) {
    NO;
    return;
  }

  YES;
  for (auto [u, v] : edges) {
    if (pos[u] < pos[v])
      cout << ++u << " " << ++v << endl;
    else
      cout << ++v << " " << ++u << endl;
  }

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