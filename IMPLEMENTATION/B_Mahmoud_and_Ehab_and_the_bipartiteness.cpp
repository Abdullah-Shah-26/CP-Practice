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
const ll LINF = 1e18;
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

void dfs(int u, int p, vi& color, vvi& adj) {
  for (int v : adj[u]) {
    if (v == p) continue;

    color[v] = color[u] ^ 1;
    dfs(v, u, color, adj);
  }
}

void solve() {
  int n;
  cin >> n;

  vvi adj(n + 1);

  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].pb(v);
    adj[v].pb(u);
  }

  vi color(n + 1, -1);
  color[1] = 0;

  dfs(1, 0, color, adj);

  ll cnt0 = 0, cnt1 = 0;

  for (int i = 1; i <= n; i++) {
    if (color[i] == 0)
      cnt0++;
    else
      cnt1++;
  }

  cout << cnt0 * cnt1 - (n - 1) << endl;
}

int main() {
  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}