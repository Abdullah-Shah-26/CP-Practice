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
  ll n, q;
  cin >> n >> q;

  vll a(n);
  rv(a);

  vll pref1(n + 1, 0), pref2(n + 1, 0);

  for (int i = 1; i <= n; i++) {
    pref1[i] = pref1[i - 1] + a[i - 1];
    pref2[i] = pref2[i - 1] + pref1[i];
  }

  // B len
  auto get = [](ll k) { return k * (k + 1) / 2; };

  auto f = [&](ll x) {
    if (x == 0) return 0LL;

    ll low = 0, high = n, k = 0;

    while (low <= high) {
      ll mid = low + (high - low) / 2;

      if (get(mid) <= x) {
        k = mid;
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }

    ll rem = x - get(k);
    return pref2[k] + pref1[rem];
  };

  while (q--) {
    ll l, r;
    cin >> l >> r;

    cout << f(r) - f(l - 1) << endl;
  }
}

int main() {
  int t = 1;
  // cin >> t;

  while (t--) {
    solve();
  }
  return 0;
}