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

  vvi adj(n);
  vi deg(n, 0);
  int maxd = 0;

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;

    deg[u]++;
    deg[v]++;
    maxd = max({maxd, deg[u], deg[v]});

    adj[u].pb(v);
    adj[v].pb(u);
  }

  int root = -1;
  for (int i = 0; i < n; i++) {
    if (maxd == deg[i]) {
      root = i;
      break;
    }
  }

  vector<pii> ans;

  queue<int> q;
  vector<bool> vis(n, false);

  vis[root] = 1;
  q.push(root);

  while (!q.empty()) {
    int u = q.front();
    q.pop();

    for (int v : adj[u]) {
      if (!vis[v]) {
        vis[v] = 1;
        ans.push_back({u, v});
        q.push(v);
      }
    }
  }

  for (auto [u, v] : ans) {
    cout << ++u << " " << ++v << endl;
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