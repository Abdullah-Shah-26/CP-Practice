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

vi buildCycle(int u, int v, vi& parent) {
  int n = parent.size();

  vb seen(n, false);

  int cur = u;

  // u -> root
  while (1) {
    seen[cur] = 1;

    if (cur == parent[cur]) break;

    cur = parent[cur];
  }

  cur = v;

  while (!seen[cur]) cur = parent[cur];

  int lca = cur;

  // u -> lca
  vi cycle;

  cur = u;

  while (cur != lca) {
    cycle.pb(cur);
    cur = parent[cur];
  }

  cycle.pb(cur);

  // lca -> v
  vi other;

  cur = v;

  while (cur != lca) {
    other.pb(cur);
    cur = parent[cur];
  }

  reverse(all(other));

  for (int x : other) cycle.pb(x);

  return cycle;
}

void solve() {
  int n, m;
  cin >> n >> m;

  vvi adj(n);

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;

    adj[u].pb(v);
    adj[v].pb(u);
  }

  vi color(n, -1), parent(n, -1);
  parent[0] = 0;

  // -1 (not visited), colors - {0,1}

  queue<int> q;
  vi cycle;

  color[0] = 0;
  q.push(0);

  while (!q.empty() && cycle.empty()) {
    int u = q.front();
    q.pop();

    for (int v : adj[u]) {
      if (color[v] == -1) {
        color[v] = 1 - color[u];
        parent[v] = u;
        q.push(v);
      }
      // Odd cycle found
      else if (color[v] == color[u]) {
        cycle = buildCycle(u, v, parent);
        break;
      }
    }
  }

  if (cycle.empty()) {
    cout << -1 << endl;
  } else {
    cout << cycle.size() << endl;

    for (int v : cycle) {
      cout << v + 1 << " ";
    }

    cout << endl;
  }
}

int main() {
  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}