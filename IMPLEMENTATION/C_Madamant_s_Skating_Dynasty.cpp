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
const int MOD = 998244353;

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

ll binExpo(ll a, ll b) {
  ll ans = 1;

  while (b) {
    if (b & 1) ans = ans * a % MOD;

    a = a * a % MOD;
    b >>= 1;
  }

  return ans;
}

void solve() {
  int n;
  cin >> n;

  vll a(n);
  rv(a);

  sort(all(a));

  ll fact = 1;

  for (int i = 1; i <= n - 1; i++) fact = fact * i % MOD;

  ll ans = 0;
  ll ssum = 0;  // Suffix sum

  for (int i = n - 1; i >= 0; i--) {
    if (i < n - 1) {
      
      // Choices
      ll cnt = n - i - 1;

      ll ecost = ssum - cnt * a[i] % MOD;
      ecost = (ecost % MOD + MOD) % MOD;

      ll ways = fact * binExpo(cnt, MOD - 2) % MOD;

      ans = (ans + ways * ecost) % MOD;
    }

    ssum = (ssum + a[i]) % MOD;
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