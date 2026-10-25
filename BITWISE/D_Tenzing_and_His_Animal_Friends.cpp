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

u - v
Count total duration of games where one of u, v participates
Total must be at max y

Max flow min cut
Dinic algo

==========================
*/

int n, m;
ll dis[100][100];

void solve() {
  cin >> n >> m;

  // Acts as +INF
  memset(dis, 0x3f, sizeof dis);

  while (m--) {
    int u, v;
    ll y;

    cin >> u >> v >> y;
    u--, v--;

    dis[u][v] = dis[v][u] = y;
  }

  // i -> i distance = 0
  for (int i = 0; i < n; i++) dis[i][i] = 0;

  for (int k = 0; k < n; k++)
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);

  if (dis[0][n - 1] > (ll)1e18) {
    cout << "inf" << endl;
    return;
  }

  int ord[100];
  iota(ord, ord + n, 0);

  sort(ord + 1, ord + n, [](auto a, auto b) { return dis[0][a] < dis[0][b]; });

  string s(n, '0');
  vector<pair<string, ll>> ans;  // [mask, duration]

  for (int i = 0; i < n - 1; i++) {
    int u = ord[i];
    int v = ord[i + 1];

    s[u] = '1';

    ans.pb({s, dis[0][v] - dis[0][u]});

    if (v == n - 1) break;
  }

  cout << dis[0][n - 1] << " " << ans.size() << endl;
  for (auto [mask, t] : ans) cout << mask << " " << t << endl;
}

int main() {
  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}