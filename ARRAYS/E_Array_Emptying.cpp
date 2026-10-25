
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



==========================
*/

struct SegTree {
  int n;
  vi mx, lazy;

  SegTree(const vi& a) {
    n = (int)a.size() - 1;
    mx.assign(4 * n + 4, 0);
    lazy.assign(4 * n + 4, 0);
    build(1, 1, n, a);
  }

  void build(int node, int l, int r, const vi& a) {
    if (l == r) {
      mx[node] = a[l];
      return;
    }

    int mid = (l + r) / 2;
    build(2 * node, l, mid, a);
    build(2 * node + 1, mid + 1, r, a);

    pull(node);
  }

  void pull(int node) {
    mx[node] = max(mx[2 * node], mx[2 * node + 1]) + lazy[node];
  }

  void push(int node) {
    if (lazy[node] == 0) return;

    for (int child : {2 * node, 2 * node + 1}) {
      mx[child] += lazy[node];
      lazy[child] += lazy[node];
    }

    lazy[node] = 0;
  }

  void upd(int node, int l, int r, int ql, int qr, int val) {
    if (ql > r || qr < l || ql > qr) return;

    if (ql <= l && r <= qr) {
      mx[node] += val;
      lazy[node] += val;
      return;
    }

    push(node);

    int mid = (l + r) / 2;
    upd(2 * node, l, mid, ql, qr, val);
    upd(2 * node + 1, mid + 1, r, ql, qr, val);

    pull(node);
  }

  void upd(int l, int r, int val) {
    if (l > r) return;
    upd(1, 1, n, l, r, val);
  }

  // Rightmost i whose value > lim.
  // 0 if no such i found.
  int rightmost(int node, int l, int r, int lim) {
    if (mx[node] <= lim) return 0;
    if (l == r) return l;

    push(node);

    int mid = (l + r) / 2;

    int res = rightmost(2 * node + 1, mid + 1, r, lim);
    if (res) return res;

    return rightmost(2 * node, l, mid, lim);
  }

  int rightmost(int lim) { return rightmost(1, 1, n, lim); }
};

void solve() {
  int n, k;
  cin >> n >> k;

  vi cnt0(n + 2, 0);

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    cnt0[x]++;
  }

  vi f(n + 2, 0);
  int suff = 0;

  for (int v = n; v >= 1; v--) {
    suff += cnt0[v];
    f[v] = suff + v;
  }

  auto check = [&](int s) {
    vi cnt = cnt0;
    set<int> st;

    for (int v = 1; v <= n; v++)
      if (cnt[v]) st.insert(v);

    SegTree seg(f);
    int lim = k + n + 2 * s;

    for (int it = 0; it <= s; it++) {
      int v = seg.rightmost(lim);

      if (v == 0) return true;

      if (it == s) return false;

      int x = *st.lower_bound(v);
      int h = (x + 1) / 2;

      if (--cnt[x] == 0) st.erase(x);

      if (cnt[h] == 0) st.insert(h);

      cnt[h] += 2;

      seg.upd(1, h, 1);
      seg.upd(h + 1, x, -1);
    }

    return false;
  };

  int low = 0, high = 2 * n + 2;
  int ans = high;

  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (check(mid)) {
      ans = mid;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }

  cout << n + 2 * ans << endl;
}

int main() {
  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}

