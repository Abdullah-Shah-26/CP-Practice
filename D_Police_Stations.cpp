#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// Ordered Set
#define oset                                   \
  tree<int, null_type, less<int>, rb_tree_tag, \
       tree_order_statistics_node_update>
// order_of_key(k) : No of Elements < k
// *find_by_order(i) : Value at idx i (0 - based)

// ---------- Type aliases ----------
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using vs = vector<string>;
using vb = vector<bool>;
using vpi = vector<pi>;
using vvpi = vector<vector<pi>>;

// ---------- Constants ----------
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;

// ---------- Fast IO ----------
static const auto fastio = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}();

// ---------- Macros ----------
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
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define eb emplace_back
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define per(i, a, b) for (int i = (b) - 1; i >= (a); --i)
#define nl        \
  do {            \
    cout << '\n'; \
  } while (0)

int n, k, d;
vector<vector<pair<int, int>>> adj;  // {neiNode, edgeId}
vector<bool> vis;
vector<bool> edgeUsed;

// ---------- Solve ---------
void solve() {
  cin >> n >> k >> d;

  adj.resize(n + 1);
  vis.resize(n + 1);
  edgeUsed.resize(n, false);

  queue<int> q;

  // BFS Multisource
  for (int i = 0; i < k; i++) {
    int p;
    cin >> p;

    // Avoiding duplicate police station
    if (!vis[p]) {
      q.push(p);
      vis[p] = 1;
    }
  }

  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back({v, i});
    adj[v].push_back({u, i});
  }

  while (!q.empty()) {
    int u = q.front();
    q.pop();

    for (auto [v, idx] : adj[u]) {
      if (!vis[v]) {
        vis[v] = 1;
        edgeUsed[idx] = 1;
        q.push(v);
      }
    }
  }

  vi deletedRoads;
  for (int i = 1; i < n; i++) {
    if (!edgeUsed[i]) {
      deletedRoads.push_back(i);
    }
  }

  cout << deletedRoads.size() << endl;
  pv(deletedRoads);
}

// ---------- Main ----------
int main() {
  solve();
  return 0;
}