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
const ll LINF = 1e18;
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

/*
==========================



==========================
*/

int query(int i, int j) {
  cout << "? " << i << " " << j << endl;

  int x;
  cin >> x;

  if (x == -1) exit(0);

  return x;
}

void solve() {
  int n;
  cin >> n;

  vi ans(n + 1);

  int mx = 1;

  for (int i = 2; i <= n; i++) {
    int a = query(mx, i); // p[mx] % p[i]
    int b = query(i, mx); // p[i] % p[mx]

    // p[mx] % p[i] = p[mx] if mx is smaller
    // p[i] % p[mx] = something but < p[mx]
    // So max(p[mx], something < p[mx]) = p[mx]

    if (a > b) {
      // mx is smaller, a = p[mx]
      ans[mx] = a;
      mx = i;
    } else {
      // i is smaller,
      ans[i] = b;

      // mx remains larger
    }
  }

  // The pos which never got assigned as its maximum
  ans[mx] = n;

  cout << "! ";
  for (int i = 1; i <= n; i++) cout << ans[i] << " ";

  cout << endl;
}

int main() {
  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}