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

ll find(ll l, ll r, ll cur, ll slope, ll k) {
  if (slope == 0) return cur == k ? l : -1;

  ll diff = k - cur;
  ll steps = diff / slope;

  if (diff % slope != 0) return -1;
  if (steps < 0 || steps > r - l) return -1;

  return l + steps;
}

void solve() {
  ll n, m, k;
  cin >> n >> m >> k;

  map<ll, ll> events;
  ll inf = 0;

  for (ll i = 0; i < n; i++) {
    ll l, r;
    cin >> l >> r;

    ll L = max(l, 1LL);
    ll R = min(r, m);

    if (L <= R) inf += (R - L + 1);

    events[l - m]++;
    events[r - m + 1]--;

    events[l]--;
    events[r + 1]++;
  }

  ll slope = 0;

  for (auto [pos, delta] : events) {
    if (pos > 1) break;

    slope += delta;
  }

  ll curs = 1;

  for (auto it = events.upper_bound(1); it != events.end(); it++) {
    ll nexts = it->first;
    ll ans = find(curs, nexts - 1, inf, slope, k);

    if (ans != -1) {
      cout << ans << endl;
      return;
    }

    inf += (nexts - curs) * slope;
    curs = nexts;

    slope += it->second;
  }

  if (inf == k)
    cout << curs << endl;
  else
    cout << -1 << endl;
}

int main() {
  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}