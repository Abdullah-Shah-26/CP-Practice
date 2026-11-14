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

int n, m, a, b, c;

// a -> 1 x 2 Horizontal
// b -> 2 x 1 Vertical
// c -> 2 x 2 Square

void solve() {
  cin >> n >> m >> a >> b >> c;

  int hori = a;
  int vert = b;
  int sq = c;

  // Odd area can't be fully tiled
  if (n % 2 && m % 2) {b
    cout << "IMPOSSIBLE" << endl;
    return;
  }

  // Odd col's, 1 col left, need to reverse verticals
  if (m % 2) vert -= n / 2;

  if (n % 2) hori -= m / 2;

  if (hori < 0 || vert < 0) {
    cout << "IMPOSSIBLE" << endl;
    return;
  }

  // No of 2x2
  int blocks = (n / 2) * (m / 2);

  int useSq = min(blocks, sq);
  int rem = blocks - useSq;

  if (hori / 2 + vert / 2 < rem) {
    cout << "IMPOSSIBLE" << endl;
    return;
  }

  vs ans(n, string(m, '?'));

  // Each itr processes 2x2 block
  for (int i = 0; i + 1 < n; i += 2) {
    for (int j = 0; j + 1 < m; j += 2) {
      int br = i / 2;
      int bc = j / 2;
      int color = (br % 2) * 2 + (bc % 2);

      char x = 'a' + 2 * color;
      char y = x + 1;

      // 2x2
      if (sq > 0) {
        ans[i][j] = ans[i + 1][j] = ans[i][j + 1] = ans[i + 1][j + 1] = x;
        sq--;
      } else if (hori >= 2) {
        ans[i][j] = ans[i][j + 1] = x;
        ans[i + 1][j] = ans[i + 1][j + 1] = y;
        hori -= 2;
      } else if (vert >= 2) {
        ans[i][j] = ans[i + 1][j] = x;
        ans[i][j + 1] = ans[i + 1][j + 1] = y;
        vert -= 2;
      }
    }
  }

  // Fill last col using vert
  if (m % 2) {
    int idx = 0;

    for (int r = 0; r < n; r += 2) {
      char ch = (idx % 2 == 0) ? 'i' : 'j';
      ans[r][m - 1] = ans[r + 1][m - 1] = ch;
      idx++;
    }
  }

  // Fill last row using hori
  if (n % 2) {
    int idx = 0;

    for (int c = 0; c < m; c += 2) {
      char ch = (idx % 2 == 0) ? 'i' : 'j';
      ans[n - 1][c] = ans[n - 1][c + 1] = ch;
      idx++;
    }
  }

  for (auto& r : ans) cout << r << endl;

  return;
}

int main() {
  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}