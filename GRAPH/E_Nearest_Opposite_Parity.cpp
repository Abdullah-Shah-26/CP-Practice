#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

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
#define rm(mat)         \
  for (auto& r : (mat)) \
    for (auto& x : (r)) cin >> x
#define pm(mat)                                   \
  do {                                            \
    for (const auto& r : (mat)) {                 \
      for (const auto& x : (r)) cout << x << ' '; \
      cout << '\n';                               \
    }                                             \
  } while (0)
#define pf(x) cout << x << '\n'
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define pb push_back
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define endl '\n'

/*
==========================
Observation / Thinking
--------------------------

i - ai <---- i ----> i + ai

For each i
min moves to reach pos j
such that ai & aj has opposite parity

Contains new idea 
Interesting question : 

Just reversing edges maintains our index constraint 

Going from dest of targetPairty to src of OppositeParity ensures we reach valid dest -> src 

We can reach that src via multiple valid dest

We want the shortest one 

Undirected graph: Multi-source BFS from targets is enough.

Directed graph: Reverse the graph, then perform multi-source BFS from the targets.

==========================
*/

int n;
vi ans, a;
vvi revAdj;

void bfs(int stParity, int targetParity) {
  queue<int> q;
  vi dist(n + 1, -1);

  // Push valid destinations
  for (int i = 1; i <= n; i++) {
    if (a[i] % 2 == targetParity) {
      q.push(i);
      dist[i] = 0;
    }
  }

  while (!q.empty()) {
    int u = q.front();
    q.pop();

    for (int v : revAdj[u]) {
      if (dist[v] == -1) {
        dist[v] = dist[u] + 1;
        q.push(v);
      }
    }
  }

  for(int i = 1; i <= n; i++){
    if(a[i] % 2 == stParity){
      ans[i] = dist[i];
    }
  }
}

void solve() {
  cin >> n;
  a.resize(n + 1);
  revAdj.resize(n + 1);
  ans.assign(n + 1, -1);

  for (int i = 1; i <= n; i++) cin >> a[i];

  // rev graph
  for (int i = 1; i <= n; i++) {
    int left = i - a[i];
    int right = i + a[i];

    if (left >= 1) {
      revAdj[left].pb(i);
    }
    if (right <= n) {
      revAdj[right].pb(i);
    }
  }

  // BFS for even targeting odd
  bfs(0, 1);

  // BFS for odd targeting even
  bfs(1, 0);

  for (int i = 1; i <= n; i++) cout << ans[i] << " ";
}

int main() {
  int t = 1;
  // cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}