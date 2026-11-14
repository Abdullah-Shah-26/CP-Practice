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
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define endl '\n'

/*
==========================



==========================
*/

struct Fenwick {
  int n;
  vll bit;

  Fenwick(int n) : n(n), bit(n + 1, 0) {}

  void add(int i, ll val) {
    while (i <= n) {
      bit[i] += val;
      i += i & -i;
    }
  }

  ll sum(int i) {
    ll ans = 0;

    while (i > 0) {
      ans += bit[i];
      i -= (i & -i);
    }

    return ans;
  }

  ll rangeSum(int l, int r) {
    if (l > r) return 0;

    return sum(r) - sum(l - 1);
  }
};

void solve() {
  int n;
  cin >> n;

  vll a(n);
  vi p(n);

  rv(a);

  for (auto& x : p) {
    cin >> x;
    x--;
  }

  reverse(all(p));

  Fenwick ft(n);
  set<int> imp;  // pos where champion changes
  vi ans(n);

  for (int i = 0; i < n; i++) {
    int k = p[i];  // pos of sorcer we are adding back

    int last = -1;
    auto it = imp.upper_bound(k);

    if (it == imp.begin() || ft.rangeSum(*prev(it) + 1, k) < a[k]) {
      imp.insert(k);
      last = k;  // Last champion change before k or k itself
    } else {
      last = *prev(it);
    }

    ft.add(k + 1, a[k]);

    while (1) {
      auto jt = imp.upper_bound(k);

      if (jt == imp.end()) break;

      int j = *jt;

      if (ft.rangeSum(last + 1, j) >= a[j]) {
        imp.erase(j);
      } else
        break;
    }

    ans[i] = (int)imp.size() - 1;
  }

  reverse(all(ans));

  for (auto& x : ans) cout << x << " ";
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