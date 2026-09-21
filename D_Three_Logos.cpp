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
  int x[3], y[3];
  for (int i = 0; i < 3; i++) cin >> x[i] >> y[i];

  int area = x[0] * y[0] + x[1] * y[1] + x[2] * y[2];

  int n = sqrt(area);

  if (n * n != area) {
    cout << -1 << '\n';
    return;
  }

  for (int mask = 0; mask < 8; mask++) {
    int w[3], h[3];

    for (int i = 0; i < 3; i++) {
      if (mask & (1 << i)) {
        w[i] = y[i];
        h[i] = x[i];
      } else {
        h[i] = y[i];
        w[i] = x[i];
      }
    }

    if (h[0] == n && h[1] == n && h[2] == n && w[0] + w[1] + w[2] == n) {
      cout << n << endl;

      for (int i = 0; i < n; i++) {
        for (int j = 0; j < w[0]; j++) cout << 'A';

        for (int j = 0; j < w[1]; j++) cout << 'B';

        for (int j = 0; j < w[2]; j++) cout << 'C';

        cout << endl;
      }
      return;
    }

    for (int top = 0; top < 3; top++) {
      int a = (top + 1) % 3;
      int b = (top + 2) % 3;

      // The rectangle at the top should take up full width
      if (w[top] != n) continue;

      int rem = n - h[top];

      // The other 2 rectangles should be able to fit in the remaining height
      if (h[a] != rem || h[b] != rem) continue;

      if (w[a] + w[b] != n) continue;

      cout << n << endl;

      for (int i = 0; i < h[top]; i++) {
        for (int j = 0; j < n; j++) cout << char('A' + top);
        cout << endl;
      }

      for (int i = 0; i < rem; i++) {
        for (int j = 0; j < w[a]; j++) cout << char('A' + a);
        for (int j = 0; j < w[b]; j++) cout << char('A' + b);

        cout << endl;
      }

      return;
    }
  }

  cout << -1 << endl;
  return;
}

int main() {
  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}