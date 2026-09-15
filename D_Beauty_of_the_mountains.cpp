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

void solve() {
  int n, m, k;
  cin >> n >> m >> k;

  int a[n][m];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> a[i][j];

  int type[n][m];
  ll D = 0;  // diff = sum of ht of 0 - sum of ht of 1

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char x;
      cin >> x;

      if (x == '0') {
        type[i][j] = 0;
        D += a[i][j];  // Contributes to snowy
      } else {
        type[i][j] = 1;
        D -= a[i][j];  // Subtracts non snowy sum
      }
    }
  }

  D = abs(D);
  if (D == 0) {
    YES;
    return;
  }

  int G = 0;

  for (int i = 0; i <= n - k; i++) {
    int window = 0;  // balance of window (k*k)

    for (int x = i; x < i + k; x++) {
      for (int y = 0; y < k; y++) {
        window += (type[x][y] == 0 ? 1 : -1);
      }
    }

    G = __gcd(G, abs(window));

    for (int y = 0; y <= m - k; y++) {
      for (int x = i; x < i + k; x++) {
        window += (type[x][y - 1] == 0 ? -1 : 1);
        window += (type[x][y + k - 1] == 0 ? 1 : -1);
      }

      G = __gcd(G, abs(window));
    }

    if (G != 0 && D % G == 0) {
      YES;
      return;
    } else {
      NO;
      return;
    }
  }

  return;
}

int main() {
  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}