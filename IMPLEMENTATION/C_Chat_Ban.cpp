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
#define endl '\n'

/*
==========================



==========================
*/

void solve() {
  ll k, x; // Limit on cumulative sum = x
  cin >> k >> x;

  if (x > k * k) {
    cout << 2 * k - 1 << endl;
    return;
  }

  ll ans1 = 0;

  // BS
  // 1 .... k

  ll low = 1, high = k;

  while (low <= high) {
    ll mid = low + (high - low) / 2;

    ll sum = mid * (mid + 1) / 2;

    if (sum >= x) {
      ans1 = mid;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }

  ll peak = 1LL * k * (k + 1) / 2;

  if (x <= peak) {
    cout << ans1 << endl;
    return;
  }

  // BS
  // (k-1) .... 1

  ll ans2 = 0;
  ll need = x - peak;

  low = 1, high = k - 1;

  while (low <= high) {
    ll mid = (low) + (high - low) / 2; // No of messages 

    ll sum = mid * (2 * k - mid - 1) / 2; // Cumulative sum uptil this message

    if (sum >= need) {
      ans2 = mid;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }

  if (ans2 == 0) {
    cout << 2 * k - 1 << endl;
    return;
  }

  cout << k + ans2 << endl;
}

int main() {
  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
