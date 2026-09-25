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
#define rm(mat)         \
  for (auto& r : (mat)) \
    for (auto& x : (r)) cin >> x
#define pm(mat)                                   \
  do {                                            \
    for (const auto& r : (mat)) {                 \
      for (const auto& x : (r)) cout << x << ' '; \
      cout << '\n';                               \
    }                                             \
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

int a[200000];
int pref[33][200001];
// pref[bit][i] = cnt of zero in bit among a[0...i-1]

int rangeAnd(int l, int r) {
  int ans = 0;

  for (int i = 0; i < 32; i++) {
    // No of zeros in that bit from a[0] to a[i-1] is 0
    // Implies everyone has 1

    if (pref[i][r + 1] - pref[i][l] == 0) {
      ans |= (1 << i);
    }
  }

  return ans;
}

void solve() {
  ll n;
  cin >> n;

  for (int i = 0; i < n; i++) cin >> a[i];

  for (int j = 0; j < 32; j++) {
    pref[j][0] = 0;  // empty pref has 0 zeros

    for (int i = 0; i < n; i++) {
      if ((1 << j) & a[i]) {
        pref[j][i + 1] = pref[j][i];
      } else {
        pref[j][i + 1] = pref[j][i] + 1;
      }
    }
  }

  ll q;
  cin >> q;

  while (q--) {
    ll l, k;
    cin >> l >> k;

    l--;

    // AND over an expanding range is non-increasing; if a[l] < k, no r can
    // satisfy
    if (a[l] < k) {
      cout << -1 << " ";
      continue;
    }

    // Binary search the maximum r such that AND(a[l..r]) >= k
    ll low = l, high = n - 1;
    ll maxr = l;

    while (low <= high) {
      ll mid = (low + high) >> 1;

      if (rangeAnd(l, mid) >= k) {
        maxr = mid;
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }

    cout << maxr + 1 << " ";
  }

  cout << endl;
}

int main() {
  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}