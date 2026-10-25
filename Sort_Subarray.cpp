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

i,
1 (n - k + 1)

sort them

==========================
*/

void solve() {
  ll n, k;
  cin >> n >> k;

  vll a(n);
  rv(a);

  vb pref(n, 1);
  for (int i = 1; i < n; i++) pref[i] = pref[i - 1] && (a[i - 1] <= a[i]);

  vb suff(n, 1);
  for (int i = n - 2; i >= 0; i--) suff[i] = suff[i + 1] && (a[i + 1] >= a[i]);

  deque<ll> mn, mx;

  for (int r = 0; r < n; r++) {
    while (!mn.empty() && a[mn.back()] >= a[r]) mn.pop_back();

    mn.push_back(r);

    while (!mx.empty() && a[mx.back()] <= a[r]) mx.pop_back();

    mx.push_back(r);

    int l = r - k + 1;

    if (l < 0) continue;

    while (!mn.empty() && mn.front() < l) mn.pop_front();

    while (!mx.empty() && mx.front() < l) mx.pop_front();

    ll mini = a[mn.front()];
    ll maxi = a[mx.front()];

    if (l > 0 && !pref[l - 1]) continue;

    if (r + 1 < n && !suff[r + 1]) continue;

    if (l > 0 && a[l - 1] > mini) continue;

    if (r + 1 < n && a[r + 1] < maxi) continue;

    YES;
    return;
  }

  NO;
  return;
}

int main() {
  int t = 1;
  // cin >> t;

  while (t--) {
    solve();
  }
  return 0;
}