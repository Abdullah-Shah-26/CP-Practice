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
const int MOD = 1073741824;

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
  ll a, b, c;
  cin >> a >> b >> c;

  ll n = 1e6;

  vll cnt(n + 1);

  for (ll d = 1; d <= 1e6; d++) {
    for (ll x = d; x <= n; x += d) {
      cnt[x]++;
    }
  }

  ll sum = 0;
  for (ll i = 1; i <= a; i++) {
    for (ll j = 1; j <= b; j++) {
      for (ll k = 1; k <= c; k++) {
        ll prod = (i * j * k);
        sum = (sum + cnt[prod]) % MOD;
      }
    }
  }

  cout << sum << endl;
}

int main() {
  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}