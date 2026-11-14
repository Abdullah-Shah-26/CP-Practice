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

const int N = 200005;

vi adj[N];
vb vis(N, false);
vi euler;

void dfs(int u) {
  vis[u] = true;
  euler.pb(u);

  for (int v : adj[u]) {
    if (vis[v]) continue;

    dfs(v);
    euler.pb(u);
  }
}

void solve() {
  int n, m, k;
  cin >> n >> m >> k;

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].pb(v);
    adj[v].pb(u);
  }

  dfs(1);

  // ceil (2 * n) / k
  int sz = (2 * n + k - 1) / k;

  int pos = 0;
  for (int i = 0; i < k; i++) {
    int cnt = min(sz, (int)euler.size() - pos);

    // CLONE HAS NOTHING TO COVER, ANY SINGLE VERTEX IS VALID
    if (cnt <= 0) {
      cout << 1 << " " << 1 << endl;
      continue;
    }

    cout << cnt << " ";

    for (int j = 0; j < cnt; j++) cout << euler[pos++] << " ";

    cout << endl;
  }
}

int main() {
  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}