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

s = 100010
10010
0010
010
ans = 3

Final s must have |d0 - d1| <= 1

==========================
*/

void solve() {
  int n;
  cin >> n;

  string s;
  cin >> s;

  ll c0 = 0, c1 = 0;
  for (char& ch : s) {
    if (ch == '0')
      c0++;
    else
      c1++;
  }

  ll m0 = 0, m1 = 0;
  rep(i, 0, n) {
    if (i == 0 || s[i] != s[i - 1]) {
      if (s[i] == '0')
        m0++;
      else
        m1++;
    }
  }

  ll ans = -1;
  ll diff = c0 - c1;

  for (ll k = -1; k <= 1; k++) {
    if (abs(diff - k) <= 1) {
      ll s1 = min(m1, m0 - k);

      if (s1 >= max(0LL, -k)) {
        ll len = 2 * s1 + k;
        ll ops = n - len;

        if (ans == -1 || ops < ans) ans = ops;
      }
    }
  }

  pf(ans);
}

int main() {
  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}