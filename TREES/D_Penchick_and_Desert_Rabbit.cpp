#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// Ordered Set
#define oset                                   \
  tree<int, null_type, less<int>, rb_tree_tag, \
       tree_order_statistics_node_update>
// order_of_key(k) : No of Elements < k
// *find_by_order(i) : Value at idx i (0 - based)

// ---------- Type aliases ----------
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

// ---------- Constants ----------
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;

// ---------- Fast IO ----------
static const auto fastio = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}();

// ---------- Macros ----------
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
#define nl        \
  do {            \
    cout << '\n'; \
  } while (0)

struct segTree {
  int n;
  vector<int> seg, lazy;

  void init(int N) {
    this->n = N;
    seg.resize(4 * n, 0);
    lazy.resize(4 * n, 0);
  }

  void push(int st, int end, int node) {
    if (lazy[node]) {
      seg[node] = max(lazy[node], seg[node]);

      if (st != end) {
        lazy[2 * node + 1] = max(lazy[2 * node + 1], lazy[node]);
        lazy[2 * node + 2] = max(lazy[2 * node + 2], lazy[node]);
      }

      lazy[node] = 0;
    }
  }

  int query(int st, int end, int l, int r, int node) {
    push(st, end, node);

    if (st > r || end < l) return 0;

    if (st >= l && end <= r) return seg[node];

    int mid = (st + end) / 2;

    int left = query(st, mid, l, r, 2 * node + 1);
    int right = query(mid + 1, end, l, r, 2 * node + 2);

    return max(left, right);
  }

  void update(int st, int end, int node, int l, int r, int val) {
    push(st, end, node);

    if (st > r || end < l) return;

    if (st >= l && end <= r) {
      lazy[node] = val;
      push(st, end, node);
      return;
    }

    int mid = (st + end) / 2;

    update(st, mid, 2 * node + 1, l, r, val);
    update(mid + 1, end, 2 * node + 2, l, r, val);

    seg[node] = max(seg[2 * node + 1], seg[2 * node + 2]);

    return;
  }

  int query(int l, int r) { return query(0, n - 1, l, r, 0); }

  void update(int l, int r, int x) { update(0, n - 1, 0, l, r, x); }
};

// ---------- Solve ---------
void solve() {
  int n;
  cin >> n;

  vi a(n);
  rv(a);

  segTree seg;
  seg.init(n + 1);

  multiset<int> ms;
  ms.insert(0);

  for (auto& x : a) {
    ms.insert(x);
  }

  vi ans(n);
  for (int i = n - 1; i >= 0; i--) {
    ans[i] = max(
        {seg.query(0, a[i] - 1), *ms.rbegin(), seg.query(0, *ms.rbegin() - 1)});
    seg.update(a[i], n, ans[i]);
    ms.extract(a[i]);
  }

  pv(ans);
}

// ---------- Main ----------
int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}