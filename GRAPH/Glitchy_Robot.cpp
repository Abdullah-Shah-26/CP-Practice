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
using T = tuple<ll, ll, ll>;

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
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define pb push_back
#define YES cout << "Yes\n"
#define NO cout << "No\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define endl '\n'

/*
==========================



==========================
*/

void solve() {
  ll n;
  cin >> n;

  vll a(n), p(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    p[i + 1] = p[i] + a[i];
  }

  vll pmin(n + 1), pmax(n + 1), smin(n + 1), smax(n + 1);

  pmin[0] = pmax[0] = p[0];
  for (int i = 1; i <= n; i++) {
    pmin[i] = min(pmin[i - 1], p[i]);
    pmax[i] = max(pmax[i - 1], p[i]);
  }

  smin[n] = smax[n] = p[n];
  for (int i = n - 1; i >= 0; i--) {
    smin[i] = min(smin[i + 1], p[i]);
    smax[i] = max(smax[i + 1], p[i]);
  }

  ll ans = pmax[n] - pmin[n] + 1;

  for (int i = 1; i <= n; i++) {
    ll s = -2 * a[i - 1];

    ll mn = min(pmin[i - 1], smin[i] + s);
    ll mx = max(pmax[i - 1], smax[i] + s);

    ans = max(ans, mx - mn + 1);
  }

  cout << ans << endl;
}

int main() {
  int t = 1;
  // cin >> t;

  while (t--) {
    solve();
  }
  return 0;
}