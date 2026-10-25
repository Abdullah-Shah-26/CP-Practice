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

k primes 
k exponents

Given : 2n
2k = 2n
k = n

==========================
*/

bool isPrime(ll n) {
  if (n < 2) return false;

  for (ll i = 2; i * i <= n; i++)
    if (n % i == 0) return false;

  return true;
}

ll power(ll a, ll b) {
  ll res = 1;

  while (b > 0) {
    if (b & 1) res = res * a % MOD;

    a = a * a % MOD;
    b >>= 1;
  }

  return res;
}

const int N = 5050;

ll fact[N + 1], invFact[N + 1];

vll cnt;
vector<vector<ll>> dp;

ll f(int i, int need) {
  if (i == cnt.size()) return need == 0;

  if (need < 0) return 0;

  ll& res = dp[i][need];

  if (res != -1) return res;

  // Don't choose this prime.
  res = invFact[cnt[i]] * f(i + 1, need) % MOD;

  // Choose this prime.
  if (need > 0) {
    res += invFact[cnt[i] - 1] * f(i + 1, need - 1) % MOD;
    res %= MOD;
  }

  return res;
}

void solve() {
  int n;
  cin >> n;

  vll a(2 * n);
  rv(a);

  sort(all(a));

  map<ll, ll> m;

  for (int i = 0; i < 2 * n; i++) m[a[i]]++;

  fact[0] = 1;

  for (int i = 1; i <= N; i++) fact[i] = fact[i - 1] * i % MOD;

  invFact[N] = power(fact[N], MOD - 2);

  for (int i = N; i >= 1; i--) invFact[i - 1] = invFact[i] * i % MOD;

  // Store frequencies of distinct prime values.
  for (auto [x, c] : m) {
    if (isPrime(x)) cnt.pb(c);
  }

  int sz = cnt.size();

  dp.assign(sz, vector<ll>(n + 1, -1));

  ll ans = f(0, n);

  // Non-primes can only be exponents.
  for (auto [x, c] : m) {
    if (!isPrime(x)) ans = ans * invFact[c] % MOD;
  }

  // Assign the n exponents to the n chosen primes.
  ans = ans * fact[n] % MOD;

  cout << ans << endl;
}

int main() {
  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}