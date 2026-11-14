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

vi v(20);
vector<tuple<int, int, int>> ans;

void move(int x, int f, int t) {
  if (x < 0) return;

  int other = f ^ t;

  // Same as tower of hanoi
  if (v[x] == 0) {
    move(x - 1, f, other);     // move (x - 1) rings from f to other
    ans.push_back({x, f, t});  // move xth ring from f to target
    move(x - 1, other, t);     // move those (x - 1) rings from other to target
  } else {
    move(x - v[x] - 1, f, other);
    ans.pb({x, f, t});
    move(x - v[x] - 1, other, f);
    move(x - 1, f, t);
  }
}

void solve() {
  int n;
  cin >> n;

  bool flag = 1;

  for (int i = 0; i < n; i++) {
    cin >> v[i];

    if (v[i] > i) flag = 0;
  }

  if (flag == 0) {
    NO;
    return;
  }

  move(n - 1, 1, 3);

  YES;
  cout << ans.size() << endl;
  for (auto [idx, a, b] : ans) {
    cout << idx + 1 << " " << a << " " << b << endl;
  }

  ans.clear();
}

int main() {
  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}