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

void solve() {
  ll h, w, n, q;
  cin >> h >> w >> n >> q;

  vll rows, cols;

  for (int i = 0; i < n; i++) {
    ll r, c;
    cin >> r >> c;

    rows.pb(r);
    cols.pb(c);
  }

  sort(all(rows));
  sort(all(cols));

  while (q--) {
    int t;
    cin >> t;

    if (t == 1) {
      ll u, d;
      cin >> u >> d;

      cout << upper_bound(all(rows), d) - lower_bound(all(rows), u) << endl;
    } else {
      ll l, r;
      cin >> l >> r;

      cout << upper_bound(all(cols), r) - lower_bound(all(cols), l) << endl;
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