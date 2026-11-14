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
  vs grid(5);

  for (auto& r : grid) cin >> r;

  int mn = 5;

  for (auto& row : grid) {
    int cnt0 = 0;

    for (char& ch : row) {
      if (ch == 'o') cnt0++;
    }

    mn = min(mn, 5 - cnt0);
  }

  for (int c = 0; c < 5; c++) {
    int cnt0 = 0;

    for (int r = 0; r < 5; r++) {
      if (grid[r][c] == 'o') cnt0++;
    }

    mn = min(mn, 5 - cnt0);
  }

  int diag0 = 0, adiag0 = 0;

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      if (i == j) {
        diag0 += (grid[i][j] == 'o');
      }

      if (i + j == 5 - 1) {
        adiag0 += (grid[i][j] == 'o');
      }
    }
  }

  mn = min({mn, 5 - diag0, 5 - adiag0});

  cout << mn << endl;
}

int main() {
  int t = 1;
  // cin >> t;

  while (t--) {
    solve();
  }
  return 0;
}