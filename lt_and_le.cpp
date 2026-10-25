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
#define rm(mat)         \
  for (auto& r : (mat)) \
    for (auto& x : (r)) cin >> x
#define pm(mat)                                   \
  do {                                            \
    for (const auto& r : (mat)) {                 \
      for (const auto& x : (r)) cout << x << ' '; \
      cout << '\n';                               \
    }                                             \
  } while (0)
#define pf(x) cout << x << '\n'
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define pb push_back
#define YES cout << "Yes\n"
#define NO cout << "No\n"
#define yno(a) cout << ((a) ? "Yes\n" : "No\n")
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define endl '\n'
using T = tuple<int, int, int>;

/*
==========================



==========================
*/

void solve() {
  int n, Q;
  cin >> n >> Q;

  vector<T> edges;
  vvi adj(n), radj(n);

  for (int i = 0; i < Q; i++) {
    int t, u, v;
    cin >> t >> u >> v;

    u--, v--;

    edges.pb({t, u, v});

    if (t == 0) {
      adj[u].pb(v);
      radj[v].pb(u);
    }
  }

  vi vis(n), order;

  function<void(int)> dfs1 = [&](int u) {
    vis[u] = 1;

    for (int v : adj[u]) {
      if (!vis[v]) dfs1(v);
    }

    order.pb(u);
  };

  for (int i = 0; i < n; i++)
    if (!vis[i]) dfs1(i);

  vi comp(n, -1);
  int cnt = 0;

  function<void(int)> dfs2 = [&](int u) {
    comp[u] = cnt;

    for (int v : radj[u]) {
      if (comp[v] == -1) {
        dfs2(v);
      }
    }
  };

  reverse(all(order));

  for (int s : order) {
    if (comp[s] != -1) continue;

    stack<int> st;
    st.push(s);
    comp[s] = cnt;

    while (!st.empty()) {
      int u = st.top();
      st.pop();

      for (int v : radj[u]) {
        if (comp[v] == -1) {
          comp[v] = cnt;
          st.push(v);
        }
      }
    }

    cnt++;
  }

  vvpii dag(cnt);
  vi indeg(cnt);

  for (auto [t, u, v] : edges) {
    int cu = comp[u];
    int cv = comp[v];

    if (cu == cv) {
      if (t == 1) {
        NO;
        return;
      }

      continue;
    }

    dag[cu].pb({cv, t});
    indeg[cv]++;
  }

  queue<int> q;
  vi dp(cnt, 1);

  for (int i = 0; i < cnt; i++) {
    if (indeg[i] == 0) {
      q.push(i);
    }
  }

  int done = 0;

  while (!q.empty()) {
    int u = q.front();
    q.pop();

    done++;

    for (auto [v, t] : dag[u]) {
      dp[v] = max(dp[v], dp[u] + t);

      indeg[v]--;

      if (indeg[v] == 0) q.push(v);
    }
  }

  if (done != cnt) {
    NO;
    return;
  }

  YES;

  for (int i = 0; i < n; i++) cout << dp[comp[i]] << " ";

  cout << endl;
}

int main() {
  int t = 1;
  // cin >> t;

  while (t--) {
    solve();
  }
  return 0;
}