#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
using vi = vector<int>;

static const auto fastio = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}();

#define pv(a)                                   \
  do {                                          \
    for (size_t i = 0; i < (a).size(); ++i)     \
      cout << (a)[i] << (i + 1 == (a).size() ? "" : " "); \
    cout << '\n';                               \
  } while (0)
#define pb push_back
#define pf(x) cout << x << '\n'
#define all(x) begin(x), end(x)
#define rep(i, a, b) for (int i = (a); i < (b); ++i)

struct Edge {
  int to;
  int id;
};

struct BackEdge {
  int u, v, id;
};

const int MAXN = 100005;

vector<Edge> adj[MAXN];
int depth[MAXN];
int dp[MAXN];
int parentNode[MAXN];
int parentEdge[MAXN];
int badCnt[MAXN];
bool vis[MAXN];

vector<BackEdge> backedges;
vi topo; 

void dfs(int u, int p, int d) {
  vis[u] = 1;
  depth[u] = d;
  topo.pb(u);

  for(auto &e : adj[u]){
    int v = e.to;
    int id = e.id;

    if(v == p) continue;

    if(vis[v]){
      if(depth[v] < depth[u]){
        dp[u]++; 
        dp[v]--;
        backedges.pb({u, v, id});
      }
    }
    else{
      parentNode[v] = u;
      parentEdge[v] = id; 
      dfs(v, u, d + 1);
    }
  }
}

void solve() {
  int n, m;
  if (!(cin >> n >> m)) return;

  rep(i, 1, m + 1){
    int u, v;
    cin >> u >> v;
    adj[u].pb({v, i});
    adj[v].pb({u, i});
  }

  rep(i, 1, n + 1){
    if(!vis[i]){
      dfs(i, 0, 1);
    }
  }

  // Accumulate DP values bottom-up using the reverse topo order
  for (int i = (int)topo.size() - 1; i >= 0; --i) {
    int u = topo[i];
    if (parentNode[u] != 0) {
      dp[parentNode[u]] += dp[u];
    }
  }

  // Precalculate tree path integrity count
  rep(i, 0, topo.size()){
    int u = topo[i];
    if(parentNode[u] != 0){
      badCnt[u] = badCnt[parentNode[u]] + (dp[u] != 1 ? 1 : 0);
    }  else {
      badCnt[u] = 0;
    }
  }

  vi ans;

  // Rule 1: A tree edge is valid if it is covered by exactly ONE cycle total
  rep(i, 1, n + 1) {
    if (parentNode[i] != 0 && dp[i] == 1) {
      ans.pb(parentEdge[i]);
    }
  }

  // Rule 2: A back-edge is valid if its entire covered tree path contains NO overlapping cycles
  for(auto &be : backedges){
    int u = be.u;
    int v = be.v;

    if(badCnt[u] - badCnt[v] == 0){
      ans.pb(be.id);
    }
  }

  sort(all(ans));
  pf(ans.size());
  pv(ans);
}

int main() {
  solve();
  return 0;
}