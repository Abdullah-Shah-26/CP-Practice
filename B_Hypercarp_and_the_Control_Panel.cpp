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

  vll a(n);
  rv(a);

  vi b, s;

  rep(i, 0, n) {
    if (b.empty() || b.back() != a[i]) {
      b.pb(a[i]);
      s.pb(1);
    } else
      s.back()++;
  }

  int k = b.size();

  bool add2 = false;
  rep(i, 0, k - 1) {
    if (s[i] >= 2 && s[i + 1] >= 2) {
      add2 = true;
      break;
    }
  }

  if (add2) {
    pf(k + 2);
    return;
  }

  bool add1 = false;
  rep(i, 0, k) {
    if (s[i] >= 2) {
      if (i + 1 < k && (i + 2 >= k || b[i + 2] != b[i])) {
        add1 = true;
        break;
      }
      if (i - 1 >= 0 && (i - 2 < 0 || b[i - 2] != b[i])) {
        add1 = true;
        break;
      }
    }
  }

  if (add1)
    pf(k + 1);
  else
    pf(k);
}

int main() {
  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}