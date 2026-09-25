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

int row[4] = {0, 0, -1, 1};
int col[4] = {1, -1, 0, 0};

void solve() {
  int r, c;
  cin >> r >> c;

  vector<vector<char>> mat(r, vector<char>(c, '.'));

  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cin >> mat[i][j];
    }
  }

  bool can = true;

  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (mat[i][j] == 'S') {
        for (int k = 0; k < 4; k++) {
          int ni = i + row[k];
          int nj = j + col[k];

          if (ni >= 0 && ni < r && nj >= 0 && nj < c) {
            if (mat[ni][nj] == 'W') {
              can = false;
              break;
            }

            if (mat[ni][nj] == '.') {
              mat[ni][nj] = 'D';
            }
          }
        }
      }

      if (!can) break;
    }

    if (!can) break;
  }

  if (!can) {
    NO;
    return;
  }

  if (can) {
    YES;

    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        cout << mat[i][j];
      }

      cout << endl;
    }
  }

  return;
}

int main() {
  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}