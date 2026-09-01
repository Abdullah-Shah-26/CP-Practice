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
#define pf(x) cout << x << '\n'
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
  ll n;
  cin >> n;

  char c;
  cin >> c;

  string s;
  cin >> s;

  bool check0 = true;

  for (int i = 0; i < n; i++) {
    if (s[i] != c) {
      check0 = false;
      break;
    }
  }

  if (check0) {
    cout << "0" << endl;
    return;
  }

  // Checking if 1 operation is enough

  int val1 = -1;

  for (ll i = 2; i <= n; i++) {
    bool can = true;

    for (ll j = i; j <= n; j += i) {
      if (s[j - 1] != c) {
        can = false;
        break;
      }
    }

    if (can) {
      val1 = i;
      break;
    }
  }

  if (val1 != -1) {
    cout << 1 << endl;
    cout << val1 << endl;
    return;
  } else {
    cout << 2 << endl;
    cout << n - 1 << " " << n << endl;
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