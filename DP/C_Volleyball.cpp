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

void solve() {
  int n, m;
  cin >> n >> m;

  int x, y;
  cin >> x >> y;
  x--;
  y--;

  vvpll graph(n);

  for (int i = 0; i < m; i++) {
    ll u, v, w;
    cin >> u >> v >> w;

    u--;
    v--;

    graph[u].pb({v, w});
    graph[v].pb({u, w});
  }

  vll t(n), c(n);

  for (int i = 0; i < n; i++) cin >> t[i] >> c[i];

  // taxiGraph[u] = all places taxi u can take us to
  // edge wt = cost of taxi u
  vvpll taxiGraph(n);

  // Dijkstra 1 :
  // Find where each taxi can go upto 
  // And build taxi graph
  for (int st = 0; st < n; st++) {
    vll dist(n, LINF);

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>>
        pq;

    dist[st] = 0;
    pq.push({0, st});

    while (!pq.empty()) {
      auto [d, u] = pq.top();
      pq.pop();

      if (d != dist[u]) continue;

      for (auto [v, w] : graph[u]) {
        if (d + w < dist[v]) {
          dist[v] = d + w;
          pq.push({dist[v], v});
        }
      }
    }

    // Now dist[j] tells us whether taxi at st can reach j
    for (int j = 0; j < n; j++) {
      if (dist[j] <= t[st]) {
        taxiGraph[st].pb({j, c[st]});
      }
    }
  }

  // Dijkstra 2 :
  // Find the shortest dist b/w x and y using taxi graph
  vll dist(n, LINF);
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>>
      pq;

  dist[x] = 0;
  pq.push({0, x});

  while (!pq.empty()) {
    auto [cost, u] = pq.top();
    pq.pop();

    if (cost != dist[u]) continue;

    for (auto [v, taxiCost] : taxiGraph[u]) {
      if (cost + taxiCost < dist[v]) {
        dist[v] = cost + taxiCost;
        pq.push({dist[v], v});
      }
    }
  }

  if (dist[y] == LINF)
    cout << -1 << endl;
  else
    cout << dist[y] << endl;

  return;
}

int main() {
  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}