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

int n, m, h;
vvpii adj;
vi check;

vector<ll> dj(int s) {
  vector<vector<ll>> dist(n + 1, vector<ll>(2, LINF));
  vvb vis(n + 1, vb(2, false));

  set<tuple<ll, int, int>> st;

  dist[s][check[s]] = 0;
  st.insert({0, s, check[s]});

  while (!st.empty()) {
    auto [d, u, f] = *st.begin();
    st.erase(st.begin());

    if (vis[u][f]) continue;
    vis[u][f] = true;

    for (auto [v, w] : adj[u]) {
      ll nw = w;

      if (f) nw /= 2;

      int f1 = f | check[v];

      if (!vis[v][f1] && d + nw < dist[v][f1]) {
        dist[v][f1] = d + nw;
        st.insert({dist[v][f1], v, f1});
      }
    }
  }

  vector<ll> d(n + 1);

  for (int i = 1; i <= n; i++) d[i] = min(dist[i][0], dist[i][1]);

  return d;
}

void solve() {
  cin >> n >> m >> h;

  adj.assign(n + 1, vpii(0));
  check.assign(n + 1, 0);

  for (int i = 0; i < h; i++) {
    int x;
    cin >> x;
    check[x] = 1;
  }

  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;

    adj[u].pb({v, w});
    adj[v].pb({u, w});
  }

  vector<ll> d1 = dj(1);
  vector<ll> d2 = dj(n);

  ll ans = LINF;

  for (int i = 1; i <= n; i++) ans = min(ans, max(d1[i], d2[i]));

  if (ans != LINF)
    cout << ans << endl;
  else
    cout << -1 << endl;

  return;
}

int main() {
  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}