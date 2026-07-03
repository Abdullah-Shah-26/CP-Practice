#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
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
#define eb emplace_back
#define rs resize
#define as assign
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define yno(a) cout << ((a) ? "YES\n" : "NO\n")
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define per(i, a, b) for (int i = (b) - 1; i >= (a); --i)
#define endl '\n'

/*
==========================
Observation / Thinking
--------------------------

n nodes
1 based

choose v-u
v is parent of u

remove v-u

add 1-u

make u along with its whole subtree a child of root

==========================
*/

const int N = 200005;
vi adj[N];
int parent[N];
int depth[N];
int used[N];
int n, k;

void dfsMark(int u) {
  used[u] = true;
  for (int v : adj[u]) {
    if (!used[v]) {
      dfsMark(v);
    }
  }
}

// can we make ht of tree <= h in using atmost k operations
bool can(int H, vi& order) {
  fill(used + 1, used + n + 1, 0);

  int cuts = 0;

  for (auto u : order) {
    if (depth[u] <= H) break;
    if (used[u]) continue;

    int v = u;
    for (int i = 0; i < H - 1; i++) v = parent[v];

    dfsMark(v);
    cuts++;

    if (cuts > k) return false;
  }

  return true;
}

void solve() {
  cin >> n >> k;

  for (int i = 1; i <= n; i++) adj[i].clear();

  for (int i = 2; i <= n; i++) {
    cin >> parent[i];
    adj[parent[i]].pb(i);
  }

  // BFS to compute depth
  queue<int> q;
  q.push(1);
  depth[1] = 0;

  while (!q.empty()) {
    int u = q.front();
    q.pop();

    for (int v : adj[u]) {
      depth[v] = depth[u] + 1;
      q.push(v);
    }
  }

  vi order(n);
  iota(all(order), 1);
  sort(all(order), [&](int a, int b) { return depth[a] > depth[b]; });

  int low = 1, high = n, ans = n;
  while (low <= high) {
    int mid = (low + high) >> 1;

    if (can(mid, order)) {
      ans = mid;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }

  pf(ans);
}

int main() {
  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}