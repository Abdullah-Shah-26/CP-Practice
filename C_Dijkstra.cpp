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

  vvpll adj(n);

  for (int i = 0; i < m; i++) {
    ll u, v, w;
    cin >> u >> v >> w;

    u--, v--;

    adj[u].pb({v, w});
    adj[v].pb({u, w});
  }

  vll dist(n, LINF);
  priority_queue<pll, vector<pll>, greater<pll>> pq;

  dist[0] = 0;
  pq.push({0, 0});

  vi parent(n, -1);

  while (!pq.empty()) {
    auto [d, u] = pq.top();
    pq.pop();

    // Remove stale entry
    if (d > dist[u]) continue;

    for (auto [v, w] : adj[u]) {
      if (d + w < dist[v]) {
        dist[v] = d + w;
        parent[v] = u;
        pq.push({d + w, v});
      }
    }
  }

  if (dist[n - 1] == LINF) {
    cout << -1 << endl;
    return;
  }

  vi path;

  int cur = n - 1;

  while (cur != -1) {
    path.pb(cur);
    cur = parent[cur];
  }

  reverse(all(path));

  for (int x : path) cout << x + 1 << " ";

  cout << endl;
}

int main() {
  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}