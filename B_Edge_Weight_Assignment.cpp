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

int n;
vvi adj;
vi depth;

void dfs(int u, int p, int d) {
  depth[u] = d;

  for (int v : adj[u]) {
    if (v == p) continue;

    dfs(v, u, d + 1);
  }
}

void solve() {
  cin >> n;

  adj.assign(n + 1, {});
  depth.assign(n + 1, 0);

  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].pb(v);
    adj[v].pb(u);
  }

  int root = 1;

  // Picking any leaf as root of the tree
  for (int i = 1; i <= n; i++)
    if (adj[i].size() == 1) {
      root = i;
      break;
    }

  dfs(root, 0, 0);

  // F = no of distinct vals required so that xor of all edge assignments as 0

  // If all leaves have same even depth
  // minF = 1

  int minF = 1;
  for (int i = 1; i <= n; i++) {
    if (adj[i].size() == 1 && (depth[i] & 1)) {
      minF = 3;
      break;
    }
  }

  int maxF = n - 1;
  for (int u = 1; u <= n; u++) {
    int leafs = 0;

    for (int v : adj[u]) {
      if (adj[v].size() == 1) leafs++;
    }

    // I can only assign 1 distinct wt for all these edges
    // x______
    // |  |  |
    // y  z  k
    if (leafs > 1) maxF -= (leafs - 1);
  }

  cout << minF << " " << maxF << endl;

  return;
}

int main() {
  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}