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
#define YES cout << "Yes\n"
#define NO cout << "No\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define endl '\n'

/*
==========================



==========================
*/

const int N = 2e5 + 5;

ll n;
vector<int> adj[N];
int color[N], dist[N], par[N];

void bfs(int src) {
  fill(dist, dist + n, -1);
  queue<int> q;

  q.push(src);
  dist[src] = 0;
  par[src] = -1;

  while (!q.empty()) {
    int u = q.front();
    q.pop();

    for (int v : adj[u]) {
      if (dist[v] == -1) {
        dist[v] = dist[u] + 1;
        par[v] = u;
        q.push(v);
      }
    }
  }
}

vi collect(int st, int prev, int d) {
  vpii cur = {{st, prev}};

  while (d--) {
    vpii next;

    // Came to u
    for (auto [u, from] : cur) {
      for (int v : adj[u]) {
        if (v != from) {
          next.pb({v, u});
        }
      }
    }

    cur = next;
  }

  vi ans;

  for (auto [u, from] : cur) ans.pb(u);

  return ans;
}

void solve() {
  cin >> n;

  for (int i = 1; i <= n - 1; i++) {
    int u, v;
    cin >> u >> v;

    u--, v--;

    adj[u].pb(v);
    adj[v].pb(u);
  }

  for (int i = 0; i < n; i++) cin >> color[i];

  bfs(0);
  int A = max_element(dist, dist + n) - dist;
  bfs(A);
  int B = max_element(dist, dist + n) - dist;
  int D = dist[B];

  vi path;  // diameter
  for (int v = B; v != -1; v = par[v]) path.pb(v);

  vvi g;
  if (D % 2 == 0) {
    int c = path[D / 2];
    for (int v : adj[c]) {
      g.pb(collect(v, c, D / 2 - 1));
    }
  } else {
    int c1 = path[D / 2];
    int c2 = path[D / 2 + 1];
    g.pb(collect(c1, c2, D / 2));
    g.pb(collect(c2, c1, D / 2));
  }

  ll ans = 0;
  vll total(n + 1, 0);

  for (auto& grp : g) {
    for (int v : grp) ans += total[color[v]];
    for (int v : grp) total[color[v]]++;
  }

  cout << ans << endl;
}

int main() {
  int t = 1;
  // cin >> t;

  while (t--) {
    solve();
  }
  return 0;
}