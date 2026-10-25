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

class SegTree {
  int n;
  vi odd;
  vi lazy;

  void build(int i, int l, int r, vi& a) {
    if (l == r) {
      odd[i] = a[l];
      return;
    }

    int mid = (l + r) >> 1;

    build(2 * i, l, mid, a);
    build(2 * i + 1, mid + 1, r, a);

    odd[i] = odd[2 * i] + odd[2 * i + 1];
  }

  void apply(int i, int l, int r) {
    int L = r - l + 1;

    odd[i] = L - odd[i];

    lazy[i] ^= 1;
  }

  void push(int i, int l, int r) {
    if (!lazy[i] || l == r) return;

    int mid = (l + r) >> 1;

    apply(2 * i, l, mid);
    apply(2 * i + 1, mid + 1, r);

    lazy[i] = false;
  }

  void flip(int i, int l, int r, int ql, int qr) {
    if (l > qr || r < ql) return;

    if (l >= ql && r <= qr) {
      apply(i, l, r);
      return;
    }

    push(i, l, r);

    int mid = (l + r) >> 1;

    flip(2 * i, l, mid, ql, qr);
    flip(2 * i + 1, mid + 1, r, ql, qr);

    odd[i] = odd[2 * i] + odd[2 * i + 1];
  }

 public:
  SegTree(vi& a) {
    n = a.size();

    odd.resize(4 * n);
    lazy.resize(4 * n);

    build(1, 0, n - 1, a);
  }

  void flip(int l, int r) {
    if (l <= r) flip(1, 0, n - 1, l, r);
  }

  int getOdd() { return odd[1]; }
};

void solve() {
  int n, q;
  cin >> n >> q;

  string s;
  cin >> s;

  vi a(n, 0);

  ll sum = 0;

  for (int i = 1; i < n; i++) {
    a[i] = (s[i - 1] != s[i]);

    if (a[i]) sum += 1LL * i * (n - i);
  }

  vi pref(n);

  for (int i = 1; i < n; i++) pref[i] = pref[i - 1] ^ a[i];

  SegTree seg(pref);

  auto get = [&]() -> ll {
    ll odd = seg.getOdd();
    ll even = n - odd;

    // odd changes
    ll oddsubstr = odd * even;

    return (sum + oddsubstr) / 2;
  };

  cout << get();

  while (q--) {
    int k;
    cin >> k;

    auto flipBounds = [&](int i) {
      if (i <= 0 || i >= n) return;

      if (a[i])
        sum -= 1LL * i * (n - i);
      else
        sum += 1LL * i * (n - i);

      a[i] ^= 1;

      seg.flip(i, n - 1);
    };

    flipBounds(k - 1);
    flipBounds(k);

    s[k - 1] ^= 1;

    cout << " " << get();
  }

  cout << endl;
}

int main() {
  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}