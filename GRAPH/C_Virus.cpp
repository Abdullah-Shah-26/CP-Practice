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
  ll n, m;
  cin >> n >> m;

  vll a(m);
  rv(a);

  sort(all(a));

  vll gaps;

  for (int i = 0; i < m - 1; i++) gaps.pb(a[i + 1] - a[i] - 1);

  gaps.pb(n - a[m - 1] + a[0] - 1);

  sort(rall(gaps));

  ll time = 0;
  ll saved = 0;

  for (ll i = 0; i < gaps.size(); i++) {
    ll sz = gaps[i] - 2LL * time;

    if (sz > 2) {
      saved += sz - 1;
      time += 2;
    } else {
      if (sz == 1 || sz == 2) {
        saved++;
        time++;
      }
    }
  }

  cout << n - saved << endl;
}

int main() {
  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}