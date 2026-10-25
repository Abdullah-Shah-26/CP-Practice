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

vi bfs(int src, vvi& adj) {
  int n = adj.size();

  vi dist(n, -1);
  queue<int> q;

  q.push(src);
  dist[src] = 0;

  while (!q.empty()) {
    int u = q.front();
    q.pop();

    for (int v : adj[u]) {
      if (dist[v] == -1) {
        dist[v] = dist[u] + 1;
        q.push(v);
      }
    }
  }

  return dist;
}

int findFarthest(int st, vvi& adj) {
  auto dist = bfs(st, adj);

  int maxIdx = max_element(all(dist)) - begin(dist);

  return maxIdx;
}

void solve() {
  int n;
  cin >> n;

  vector<vector<int>> adj(n);

  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;

    u--;
    v--;

    adj[u].pb(v);
    adj[v].pb(u);
  }

  int A = findFarthest(0, adj);
  int B = findFarthest(A, adj);

  auto distA = bfs(A, adj);
  auto distB = bfs(B, adj);

  vvi layer(n + 1);

  for (int i = 0; i < n; i++) {
    int d = max(distA[i], distB[i]);
    layer[d].pb(i);
  }

  vi ans(n + 1, 0);
  vi vis;

  for (int k = n; k >= 1; k--) {
    vis.insert(vis.end(), all(layer[k]));

    // No of connected components
    int cc = n - (int)vis.size() + 1;

    ans[k] = min(n, cc);
  }

  for (int i = 1; i <= n; i++) cout << ans[i] << " ";

  cout << endl;
}

int main() {
  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}