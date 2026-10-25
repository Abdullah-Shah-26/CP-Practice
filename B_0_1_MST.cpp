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
using T = tuple<ll, ll, ll>;

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
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define pb push_back
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define endl '\n'

void dfs(int u, vvll& adj, vb& vis) {
  vis[u] = 1;

  for (auto v : adj[u]) {
    if (!vis[v]) dfs(v, adj, vis);
  }
}

void solve() {
  ll n, m;
  cin >> n >> m;

  vector<T> edges(m);
  vvll adj1(n);
  vvll adj(n);

  for (int i = 0; i < m; i++) {
    ll u, v;
    cin >> u >> v;

    u--;
    v--;

    edges[i] = {u, v, 1};

    // 1 wt edges
    adj1[u].pb(v);
    adj1[v].pb(u);
  }

  for (int u = 0; u < n; u++) {
    vb has(n, false);

    has[u] = true;

    for (auto v : adj1[u]) has[v] = true;

    for (int v = 0; v < n && v != u; v++) {
      if (!has[v]) {
        // 0 wt edges
        adj[u].pb(v);
        adj[v].pb(u);
      }
    }
  }

  ll cnt = 0;

  vb vis(n, false);

  for (int i = 0; i < n; i++) {
    if (!vis[i]) {
      dfs(i, adj, vis);
      cnt++;
    }
  }

  cout << cnt - 1 << endl;
}

int main() {
  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}