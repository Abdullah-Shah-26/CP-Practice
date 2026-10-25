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

Prims Algorithm

==========================
*/

void solve() {
  int n;
  cin >> n;

  vll x(n), y(n);
  for (int i = 0; i < n; i++) cin >> x[i] >> y[i];

  vll c(n), k(n);
  rv(c);
  rv(k);

  vll minCost = c;
  vi parent(n, -1);
  vb used(n, false);

  ll totalCost = 0;

  vpii edges;
  vi stations;

  for (int it = 0; it < n; it++) {

    // Finding un-used city with min cost
    int u = -1;

    for (int i = 0; i < n; i++) {
      if (!used[i] && (u == -1 || minCost[i] < minCost[u])) {
        u = i;
      }
    }

    used[u] = true;
    totalCost += minCost[u];

    // Did we directly build power station at u
    if (parent[u] == -1) stations.pb(u);
    // Or connect to to its parent
    else
      edges.pb({u, parent[u]});

    for (int v = 0; v < n; v++) {
      if (used[v]) continue;

      ll wireCost = (abs(x[u] - x[v]) + abs(y[u] - y[v])) * (k[u] + k[v]);

      if (wireCost < minCost[v]) {
        minCost[v] = wireCost;
        parent[v] = u;
      }
    }
  }

  cout << totalCost << endl;

  cout << stations.size() << endl;

  for (int city : stations) cout << city + 1 << " ";

  cout << endl;

  cout << edges.size() << endl;

  for (auto [u, v] : edges) {
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