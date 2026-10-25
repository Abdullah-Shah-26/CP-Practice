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
  int n, m, k;
  cin >> n >> m >> k;

  vvi adj(n + 1);

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].pb(v);
    adj[v].pb(u);
  }

  set<tuple<int, int, int>> forbidden;

  for (int i = 0; i < k; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    forbidden.insert({a, b, c});
  }

  // vis[prev][cur] = did we vis cur from prev city
  vvb vis(n + 1, vb(n + 1, 0));

  // par[cur][next] = prev
  //
  vvi par(n + 1, vi(n + 1, -1));

  queue<pii> q;
  q.push({0, 1});
  vis[0][1] = true;

  pii dest = {-1, -1};

  while (!q.empty()) {
    auto [prev, cur] = q.front();
    q.pop();

    // we reached n
    if(dest.first != -1)
      break;

    for (int next : adj[cur]) {
      if (prev != 0 && forbidden.count({prev, cur, next})) continue;

      if (vis[cur][next]) continue;

      vis[cur][next] = true;
      par[cur][next] = prev;
      q.push({cur, next});

      if (next == n && dest.first == -1) {
        dest = {cur, next};
        break;
      }
    }
  }

  vi path;

  auto [prev, cur] = dest;

  if (cur == -1) {
    cout << -1 << endl;
    return;
  } else {
    while (cur != 1) {
      path.pb(cur);
      auto p = par[prev][cur];
      cur = prev;
      prev = p;
    }

    path.pb(1);
    reverse(all(path));

    cout << path.size() - 1 << endl;
    for (auto x : path) cout << x << " ";

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