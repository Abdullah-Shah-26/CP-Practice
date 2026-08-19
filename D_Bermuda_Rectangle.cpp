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

Bermuda rectangle :

S = area
axb = S

(x,y)

How many cells form (0,0) to (x,y) are in BR
==========================
*/

void solve() {
  ll s, q;
  cin >> s >> q;

  vll d;

  for (ll w = 1; w * w <= s; w++) {
    if (s % w == 0) {
      d.pb(w);

      if (w != s / w) d.pb(s / w);
    }
  }

  sort(all(d));

  vll pref(d.size());

  for (int i = 0; i < d.size(); i++) {
    ll prevW = (i == 0 ? 0 : d[i - 1]);
    ll curW = d[i];
    ll h = s / curW;

    // col : prevW + 1 ... curW have h ht
    pref[i] = (i == 0 ? 0 : pref[i - 1]) + (curW - prevW) * h;
  }

  auto sumHt = [&](ll x) {
    if (x == 0) return 0LL;

    int i = upper_bound(all(d), x) - begin(d) - 1;

    ll ans = pref[i];

    if(i + 1 < d.size()){
      ll h = s/d[i + 1];
      ans += (x - d[i]) * h;
    }

    return ans;
  };

  while (q--) {
    ll x, y;
    cin >> x >> y;

    // w * h = s
    // h = s/w
    // last w where h >= y

    ll limit = s / y;

    int i = upper_bound(all(d), limit) - begin(d) - 1;

    ll k = min(x, d[i]);

    // First k col => +y each
    ll ans = k * y;

    // Rem col upto x => + actual ht each
    ans += sumHt(x) - sumHt(k);

    cout << ans << endl;
  }
}

int main() {
  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}