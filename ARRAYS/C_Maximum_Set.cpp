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
const int MOD = 998244353;

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
  ll l, r;
  cin >> l >> r;

  ll k = 1;
  ll x = l;

  while (x <= r / 2) {
    x *= 2;
    k++;
  }

  if (k == 1) {
    cout << 1 << " " << r - l + 1 << endl;
    return;
  }

  ll p = 1LL << (k - 1);          // 2pow(k - 1)
  ll q = 3LL * (1LL << (k - 2));  // 3 * 2pow(k - 2)

  // set with all factors equal to 2
  ll c1 = max(0LL, r / p - l + 1);

  // set with one 3 and all other as 2
  ll c2 = max(0ll, r / q - l + 1);

  // The set containing 3, has (k - 1) choices 
  // Each choice results in different overall set 
  ll ans = (c1 + (k - 1) * c2) % MOD;

  cout << k << ' ' << ans << endl;
}

int main() {
  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}