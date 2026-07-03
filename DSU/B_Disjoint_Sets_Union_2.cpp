#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

// Ordered Set
#define pbds tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
// order_of_key(k) : No of Elements < k
// *find_by_order(i) : Value at idx i (0 - based)

// ---------- Type aliases ----------
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using vs = vector<string>;
using vb = vector<bool>;
using vpi = vector<pi>;
using vvpi = vector<vector<pi>>;

// ---------- Constants ----------
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;

// ---------- Fast IO ----------
static const auto fastio = []()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}();

// ---------- Newline helper ----------
inline void nl() { cout << '\n'; }

// ---------- Macros ----------
#define rv(a)         \
  for (auto &x : (a)) \
  cin >> x
#define rm(mat)         \
  for (auto &r : (mat)) \
    for (auto &x : (r)) \
  cin >> x
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sz(x) (int)(x).size()
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define per(i, a, b) for (int i = (b) - 1; i >= (a); --i)

struct DSU
{
  vector<int> parent, sz, mn, mx;

  DSU(int n)
  {
    parent.assign(n + 1, 0);
    sz.assign(n + 1, 1);
    mn.resize(n + 1);
    mx.resize(n + 1);

    for (int i = 1; i <= n; i++)
    {
      parent[i] = i;
      mx[i] = i;
      mn[i] = i;
    }
  }

  int find(int x)
  {
    if (x == parent[x])
      return x;

    return parent[x] = find(parent[x]);
  }

  void unite(int u, int v)
  {
    u = find(u);
    v = find(v);

    if (u == v)
      return;

    if (sz[u] < sz[v])
      swap(u, v);

    parent[v] = u;

    sz[u] += sz[v];
    mn[u] = min(mn[u], mn[v]);
    mx[u] = max(mx[u], mx[v]);
  }

  void get(int v)
  {
    int root = find(v);
    cout << mn[root] << " " << mx[root] << " " << sz[root] << endl;
  }
};

// ---------- Solve ---------
void solve()
{
  int n, m;
  cin >> n >> m;
  DSU ds(n);
  while (m--)
  {
    string s;
    cin >> s;
    if (s == "union")
    {
      int u, v;
      cin >> u >> v;
      ds.unite(u, v);
    }
    else
    {
      int x;
      cin >> x;
      ds.get(x);
    }
  }
}
// ---------- Main ----------
int main()
{
  solve();
  return 0;
}