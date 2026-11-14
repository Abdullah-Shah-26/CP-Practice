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

struct Node {
  int val = 0;
  bool bad = false;
};

Node merge(const Node& a, const Node& b) {
  Node ans;

  ans.bad = a.bad || b.bad || (a.val && b.val && a.val != b.val);
  ans.val = a.val ? a.val : b.val;

  return ans;
}

struct SegTree {
  int n;
  vector<Node> seg;

  SegTree(vi& a) {
    this->n = (int)a.size();
    seg.resize(4 * n);

    build(a, 1, 0, n - 1);
  }

  void build(vi& a, int i, int l, int r) {
    if (l == r) {
      seg[i].val = a[l] == -1 ? 0 : a[l];
      return;
    }

    int mid = (l + r) >> 1;

    build(a, 2 * i, l, mid);
    build(a, 2 * i + 1, mid + 1, r);

    seg[i] = merge(seg[2 * i], seg[2 * i + 1]);
  }

  void update(int i, int l, int r, int pos, int val) {
    if (l == r) {
      seg[i].val = val == -1 ? 0 : val;
      return;
    }

    int mid = (l + r) >> 1;

    if (pos <= mid)
      update(2 * i, l, mid, pos, val);
    else
      update(2 * i + 1, mid + 1, r, pos, val);

    seg[i] = merge(seg[2 * i], seg[2 * i + 1]);
  }

  Node query(int i, int l, int r, int ql, int qr) {
    if (l > qr || r < ql) return Node();

    if (l >= ql && r <= qr) return seg[i];

    int mid = (l + r) >> 1;

    return merge(query(2 * i, l, mid, ql, qr),
                 query(2 * i + 1, mid + 1, r, ql, qr));
  }
};

void solve() {
  int n, q;
  cin >> n >> q;

  vi a(n);
  rv(a);

  SegTree st(a);

  while (q--) {
    int t;
    cin >> t;

    if (t == 1) {
      int i, x;
      cin >> i >> x;
      st.update(1, 0, n - 1, i - 1, x);
    } else {
      int l, r;
      cin >> l >> r;

      if (st.query(1, 0, n - 1, l - 1, r - 1).bad)
        NO;
      else
        YES;
    }
  }
}

int main() {
  int t = 1;
  // cin >> t;

  while (t--) {
    solve();
  }
  return 0;
}