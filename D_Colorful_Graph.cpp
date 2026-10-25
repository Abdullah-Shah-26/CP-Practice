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

/*
==========================



==========================
*/

void solve() {
  int n, m;
  cin >> n >> m;

  vi c(n);
  for (int& x : c) cin >> x;

  vvi adj(n);

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;

    adj[u].pb(v);
    adj[v].pb(u);
  }

  // nei[c[u]] = set of neighboring colors for color c[u]
  vector<set<int>> nei(100001);

  for (int u = 0; u < n; u++) {
    for (int v : adj[u]) {
      if (c[u] != c[v]) {
        nei[c[u]].insert(c[v]);
      }
    }
  }

  int ans = *min_element(all(c));
  int mx = -1;

  vb present(100001, false);

  for (int x : c) present[x] = 1;

  for (int k = 1; k <= 100000; k++) {
    if (present[k] && (int)nei[k].size() > mx) {
      mx = nei[k].size();
      ans = k;
    }
  }

  cout << ans << endl;
}

int main() {
  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}