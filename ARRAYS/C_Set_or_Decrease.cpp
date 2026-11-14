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
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define endl '\n'

/*
==========================



==========================
*/

void solve() {
  ll n, k;
  cin >> n >> k;

  vll a(n);
  rv(a);

  sort(all(a));

  vll pref(n + 1);
  for (int i = 0; i < n; i++) pref[i + 1] = pref[i] + a[i];

  ll ans = LINF;

  // x = no of decrement ops
  // y = no of set ops

  for (int y = 0; y < n; y++) {
    ll num = k - pref[n - y] + a[0];
    ll den = y + 1;

    ll q = num / den;

    if (num < 0 && num % den != 0) q--;

    ll x = a[0] - q;
    x = max(0LL, x);

    ans = min(ans, x + y);
  }

  cout << ans << endl;
}

int main() {
  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}