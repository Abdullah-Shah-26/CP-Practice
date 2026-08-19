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

ll binExpo(ll a, ll b) {
  ll ans = 1;

  while (b) {
    if (b & 1) ans = ans * a % MOD;

    a = a * a % MOD;
    b >>= 1;
  }

  return ans;
}

class Combinatorics {
 private:
  int n;

  ll modInverse(ll x) { return binExpo(x, MOD - 2); }

 public:
  vector<ll> fact;
  vector<ll> invFact;

  Combinatorics(int n) {
    this->n = n;

    fact.assign(n + 1, 1);
    invFact.assign(n + 1, 1);

    for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i % MOD;

    invFact[n] = modInverse(fact[n]);

    for (int i = n - 1; i >= 0; i--)
      invFact[i] = invFact[i + 1] * (i + 1) % MOD;
  }

  ll nCr(int n, int r) {
    if (r < 0 || r > n) return 0;

    return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
  }

  ll nPr(int n, int r) {
    if (r < 0 || r > n) return 0;

    return fact[n] * invFact[n - r] % MOD;
  }
};

Combinatorics c(2e5);

void solve() {
  int n;
  cin >> n;

  vi a(n);
  rv(a);

  // X = And of all elements

  int x = a[0];
  for (int i = 1; i < n; i++) x &= a[i];

  int k = 0;  // Cnt of elements = X
  for (int i = 0; i < n; i++)
    if (x == a[i]) k++;

  ll ans = 1LL * k * (k - 1) % MOD;
  ans = ans * c.fact[n - 2] % MOD;

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