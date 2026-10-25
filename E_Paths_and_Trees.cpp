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

using P = pair<ll, int>;

/*
==========================



==========================
*/

void solve() {
  int n, m;
  cin >> n >> m;

  vector<vector<tuple<int, ll, int>>> adj(n + 1);
  vll dist(n + 1, LINF);

  for (int i = 1; i <= m; i++) {
    int u, v;
    ll wt;

    cin >> u >> v >> wt;

    adj[u].pb({v, wt, i});
    adj[v].pb({u, wt, i});
  }

  int src;
  cin >> src;

  priority_queue<P, vector<P>, greater<P>> pq;

  dist[src] = 0;
  pq.push({0, src});

  while (!pq.empty()) {
    auto [d, u] = pq.top();
    pq.pop();

    if (d != dist[u]) continue;

    for (auto [v, wt, id] : adj[u]) {
      if (d + wt < dist[v]) {
        dist[v] = d + wt;
        pq.push({dist[v], v});
      }
    }
  }

  vll best(n + 1, LINF);
  vll parentEdge(n + 1, -1);

  for (int u = 1; u <= n; u++) {
    for (auto [v, wt, id] : adj[u]) {
      
      // Edge : u -- v can be used for v
      if (dist[u] + wt == dist[v]) {
        if (wt < best[v]) {
          best[v] = wt;
          parentEdge[v] = id;
        }
      }
    }
  }

  vi ans;
  ll total = 0;

  for (int v = 1; v <= n; v++) {
    if (v == src) continue;

    total += best[v];
    ans.pb(parentEdge[v]);
  }

  // Total weight
  cout << total << endl;

  for (auto id : ans) cout << id << " ";

  cout << endl;
}

int main() {
  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}