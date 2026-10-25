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
const int MOD = 998244353;

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

  vvpii adj(n + 1);

  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;

    adj[u].pb({v, w});
  }

  vi dist(n + 1, -1);
  vvi layers = {{1}};

  // layers[d] = vertices at dist = d

  dist[1] = 0;

  for (int d = 0; !layers[d].empty(); d++) {
    vi nxt;

    for (int u : layers[d]) {
      for (auto [v, c] : adj[u]) {
        if (dist[v] < 0) {
          dist[v] = d + 1;
          nxt.pb(v);
        }
      }
    }

    layers.pb(nxt);
  }

  vi rank(n + 1, 0);
  vll val(n + 1, 0);
  vpii key(n + 1, {INF, 0});

  for (int d = 0; d + 1 < (int)layers.size(); d++) {
    
    for (int u : layers[d]) {
      for (auto [v, c] : adj[u]) {
        if (dist[v] != d + 1) continue;

        pii cand = {rank[u], c};

        if (cand < key[v]) {
          key[v] = cand;
          val[v] = (val[u] * 10LL + c) % MOD;
        }
      }
    }

    vi &cur = layers[d + 1];
    sort(all(cur), [&](int a, int b){
      return key[a] < key[b];
    });

    int r = 0; 
    for(int t = 0; t < (int)cur.size(); t++){
      if(t > 0 && key[cur[t]] != key[cur[t - 1]])
        r++;

      rank[cur[t]] = r;
    }
  }

  for (int v = 2; v <= n; v++) cout << val[v] << endl;

  return;
}

int main() {
  int t = 1;
  // cin >> t;

  while (t--) {
    solve();
  }
  return 0;
}