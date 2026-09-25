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

using T = tuple<ll, ll, ll>;

void solve() {
  int n, m;
  cin >> n >> m;

  vvpll adj(n + 1);
  for (int i = 0; i < m; i++) {
    ll u, v, w;
    cin >> u >> v >> w;

    adj[u].pb({v, w});
    adj[v].pb({u, w});
  }

  vll speed(n + 1);
  for (int i = 1; i <= n; i++) cin >> speed[i];

  vvll dist(n + 1, vll(1001, LINF));
  vvb vis(n + 1, vb(1001, false));

  set<T> pq;

  dist[1][speed[1]] = 0;
  pq.insert({0, 1, speed[1]});

  while (!pq.empty()) {
    auto [time, u, s] = *pq.begin();
    pq.erase(pq.begin());

    if (vis[u][s]) continue;

    vis[u][s] = 1;

    for (auto [v, w] : adj[u]) {
      ll nt = time + w * s;
      ll ns = min(s, speed[v]);

      if(nt < dist[v][ns]){
        dist[v][ns] = nt;
        pq.insert({nt, v, ns});
      }
    }
  }

  ll ans = *min_element(all(dist[n]));
  cout << ans << endl;
}

int main() {
  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}