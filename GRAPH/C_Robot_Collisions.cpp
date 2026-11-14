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

void solve() {
  int n, m;
  cin >> n >> m;

  vi x(n), dir(n), ans(n, -1);

  rv(x);

  for (int i = 0; i < n; i++) {
    char c;
    cin >> c;
    dir[i] = (c == 'R' ? 1 : -1);
  }

  vi order(n);
  iota(all(order), 0);

  // Sort co-ordinates
  sort(all(order), [&](int i, int j) { return x[i] < x[j]; });

  // 2 seperate stacks for even & odd pos
  vvi st(2);

  for (int i : order) {
    int parity = x[i] % 2;

    // Right moving robot : waits for left moving robo
    if (dir[i] == 1) {
      st[parity].pb(i);
    }

    // Left moving robot
    else {
      // Collide with nearest unmatched robot moving right
      if (!st[parity].empty()) {
        int j = st[parity].back();
        st[parity].pop_back();

        
        // If j was originally moving left, it was reflected at left wall then its reflected start co-ordinate is 
        int stJ = x[j];
        if (dir[j] == -1) {
          stJ = -x[j];
        }

        int time = (x[i] - stJ) / 2;

        ans[i] = ans[j] = time;
      } else {
        // There is no robot to collide at the left
        // Reflect this across left wall
        // Treat it as right moving robot starting at -x[i]
        // Only right moving robots are pushed into stack so push it
        st[parity].pb(i);
      }
    }
  }

  // Pair remaining using reflection at right wall
  for (int parity = 0; parity < 2; parity++) {
    while (st[parity].size() >= 2) {
      int i = st[parity].back();
      st[parity].pop_back();

      int j = st[parity].back();
      st[parity].pop_back();

      int stJ = x[j];

      // If j was originally moving left, it was reflected at left wall
      if (dir[j] == -1) {
        stJ = -x[j];
      }

      // And this right was reflected at right wall
      int time = (2 * m - x[i] - stJ) / 2;

      ans[i] = ans[j] = time;
    }
  }

  for (int x : ans) cout << x << " ";
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