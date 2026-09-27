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

bool isPrime(int n) {
  if (n < 2) return false;

  for (int d = 2; d * d <= n; d++)
    if (n % d == 0) return false;

  return true;
}

void solve() {
  int n, m;
  cin >> n >> m;

  int P = n - 1;

  while (!isPrime(P)) P++;

  cout << P << " " << P << endl;

  cout << 1 << " " << 2 << " " << P - (n - 2) << endl;

  for (int i = 2; i < n; i++) cout << i << " " << i + 1 << " " << 1 << endl;

  int rem = m - (n - 1);

  for (int u = 1; u <= n && rem > 0; u++) {
    for (int v = u + 1; v <= n && rem > 0; v++) {
      // We already made edges (1,2), (2,3) .. (u,u+1)
      if (v == u + 1) continue;

      cout << u << " " << v << " " << INF << endl;
      rem--;
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