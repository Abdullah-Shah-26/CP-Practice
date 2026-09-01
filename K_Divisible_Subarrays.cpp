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
#define YES cout << "Yes\n"
#define NO cout << "No\n"
#define yno(a) cout << ((a) ? "Yes\n" : "No\n")
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define endl '\n'

/*
==========================



==========================
*/

int n;
ll k;
vll memo, nxtMatch;

ll solve(int i) {
  if (i >= n) return 0;

  if (memo[i] != -1) return memo[i];

  ll ans = solve(i + 1);  // skip

  // take
  int j = nxtMatch[i];
  if (j != -1) ans = max(ans, solve(j) + 1);

  return memo[i] = ans;
}

void solve() {
  cin >> n >> k;

  vll pref(n + 1, 0);
  nxtMatch.assign(n + 1, -1);
  memo.assign(n + 1, -1);

  for (int i = 1; i <= n; i++) {
    ll x;
    cin >> x;
    pref[i] = (pref[i - 1] + x) % k;
  }

  map<ll, int> mp;
  for (int i = n; i >= 0; i--) {
    if (mp.count(pref[i])) {
      nxtMatch[i] = mp[pref[i]];
    }

    mp[pref[i]] = i;
  }

  cout << solve(0) << endl;
}

int main() {
  int t = 1;
  // cin >> t;

  while (t--) {
    solve();
  }
  return 0;
}