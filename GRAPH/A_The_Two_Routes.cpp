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

vi bfs(int st, vvi& adj) {
  int n = adj.size();

  vi dist(n, -1);
  queue<int> q;

  q.push(st);
  dist[st] = 0;

  while (!q.empty()) {
    int u = q.front();
    q.pop();

    for (int v : adj[u]) {
      if (dist[v] != -1) continue;

      // First time bfs visits this node, its the shortest distance 
      dist[v] = dist[u] + 1;
      q.push(v);
    }
  }

  return dist;
}

void solve() {
  int n, m;
  cin >> n >> m;

  vvi adj1(n), adj2(n);

  vvb adjMat(n, vb(n, false));

  // For trains
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;

    u--, v--;

    adj1[u].pb(v);
    adj1[v].pb(u);

    adjMat[u][v] = true;
    adjMat[v][u] = true;
  }

  // For buses
  for (int u = 0; u < n; u++) {
    for (int v = 0; v < n; v++) {
      if (!adjMat[u][v]) {
        adj2[u].pb(v);
        adj2[v].pb(u);
      }
    }
  }

  vi d1 = bfs(0, adj1);
  vi d2 = bfs(0, adj2);

  // Destination unreachable 
  if (d1[n - 1] == -1 || d2[n - 1] == -1) {
    cout << -1 << endl;
  } else {
    cout << max(d1[n - 1], d2[n - 1]) << endl;
  }

  return;
}

int main() {
  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}