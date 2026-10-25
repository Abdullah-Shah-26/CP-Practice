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

void solve() {
  int n, m;
  cin >> n >> m;

  int s, t;
  cin >> s >> t;

  vvi adj(n + 1);

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].pb(v);
  }

  vi dist(n + 1, INF);

  deque<int> dq;
  dist[s] = 0;
  dq.push_back(s);

  while (!dq.empty()) {
    int u = dq.front();
    dq.pop_front();

    if (adj[u].empty()) continue;

    int mn = *min_element(all(adj[u]));

    for (int v : adj[u]) {
      int wt = 1;

      if (v == mn) wt = 0;

      if (dist[u] + wt < dist[v]) {
        dist[v] = dist[u] + wt;

        if (wt == 0) {
          dq.push_front(v);
        } else {
          dq.push_back(v);
        }
      }
    }
  }

  if (dist[t] == INF) {
    cout << -1 << endl;
  } else
    cout << dist[t] << endl;
}

int main() {
  int t = 1;
  // cin >> t;

  while (t--) {
    solve();
  }
  return 0;
}