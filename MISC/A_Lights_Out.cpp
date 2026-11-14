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
  int a[3][3];

  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++) cin >> a[i][j];

  int row[5] = {0, 0, 0, 1, -1};
  int col[5] = {0, 1, -1, 0, 0};

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      int cnt = 0;

      for (int k = 0; k < 5; k++) {
        int x = i + row[k];
        int y = j + col[k];

        if (x >= 0 && x < 3 && y >= 0 && y < 3) {
          cnt += a[x][y];
        }
      }

      cout << (1 ^ (cnt % 2));
    }

    cout << endl;
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