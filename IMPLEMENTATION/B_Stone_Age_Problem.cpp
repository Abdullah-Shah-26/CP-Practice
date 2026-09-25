#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class SegTree {
  
  struct Node {
    ll sum = 0;
    ll lazy = -1;
  };

  int n;
  vector<Node> st;

  void build(int p, int l, int r, vector<int>& a) {
    if (l == r) {
      st[p].sum = a[l];
      return;
    }

    int mid = (l + r) / 2;

    build(2 * p, l, mid, a);
    build(2 * p + 1, mid + 1, r, a);

    st[p].sum = st[2 * p].sum + st[2 * p + 1].sum;
  }

  void apply(int p, int l, int r, ll x) {
    st[p].sum = (r - l + 1) * x;
    st[p].lazy = x;
  }

  void push(int p, int l, int r) {
    if (st[p].lazy == -1 || l == r) return;

    int mid = (l + r) / 2;

    apply(2 * p, l, mid, st[p].lazy);
    apply(2 * p + 1, mid + 1, r, st[p].lazy);

    st[p].lazy = -1;
  }

  void pointUpdate(int p, int l, int r, int idx, ll x) {
    if (l == r) {
      st[p].sum = x;
      return;
    }

    push(p, l, r);

    int mid = (l + r) / 2;

    if (idx <= mid)
      pointUpdate(2 * p, l, mid, idx, x);
    else
      pointUpdate(2 * p + 1, mid + 1, r, idx, x);

    st[p].sum = st[2 * p].sum + st[2 * p + 1].sum;
  }

  void rangeAssign(int p, int l, int r, ll x) { apply(p, l, r, x); }

 public:
  SegTree(vector<int>& a) {
    n = a.size() - 1;
    st.resize(4 * n);
    build(1, 1, n, a);
  }

  void update(int idx, ll x) { pointUpdate(1, 1, n, idx, x); }

  void updateAll(ll x) { rangeAssign(1, 1, n, x); }

  ll getSum() { return st[1].sum; }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;
  cin >> n >> q;

  vector<int> a(n + 1);

  for (int i = 1; i <= n; i++) cin >> a[i];

  SegTree seg(a);

  while (q--) {
    int t;
    cin >> t;

    if (t == 1) {
      int i;
      ll x;

      cin >> i >> x;

      seg.update(i, x);
    } else {
      ll x;
      cin >> x;

      seg.updateAll(x);
    }

    cout << seg.getSum() << '\n';
  }
}