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
  int n;
  cin >> n;

  map<ll, ll> cnt;

  for (int i = 0; i < n; i++) {
    ll x;
    cin >> x;
    cnt[x]++;
  }

  ll ans = 0;

  // b = 1
  for (auto [y, c] : cnt) {
    ans += c * (c - 1) * (c - 2);
  }

  // b > 1
  for (auto [y, c] : cnt) {
    if (y > 1000000) {
      // b is at most 1e9 / y <= 1000
      for (ll b = 2; y * b <= 1000000000LL; b++) {
        if (y % b == 0) {
          ll x = y / b;
          ll z = y * b;

          if (cnt.count(x) && cnt.count(z)) {
            ans += c * cnt[x] * cnt[z];
          }
        }
      }
    } else {
      // Enumerate divisors of y.
      for (ll b = 2; b * b <= y; b++) {
        if (y % b != 0) continue;

        // b is a possible ratio
        ll x = y / b;
        ll z = y * b;

        if (z <= 1000000000LL && cnt.count(x) && cnt.count(z)) {
          ans += c * cnt[x] * cnt[z];
        }

        // y / b is also a possible ratio
        ll b2 = y / b;

        if (b2 != b) {
          x = y / b2;
          z = y * b2;

          if (z <= 1000000000LL && cnt.count(x) && cnt.count(z)) {
            ans += c * cnt[x] * cnt[z];
          }
        }
      }

      // b = y -> x = 1, z = y²
      if (y > 1 && y * y <= 1000000000LL) {
        if (cnt.count(1) && cnt.count(y * y)) {
          ans += c * cnt[1] * cnt[y * y];
        }
      }
    }
  }

  cout << ans << '\n';
}

int main() {
  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}