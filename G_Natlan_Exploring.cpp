#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// Ordered Set
#define oset                                   \
  tree<int, null_type, less<int>, rb_tree_tag, \
       tree_order_statistics_node_update>
// order_of_key(k) : No of Elements < k
// *find_by_order(i) : Value at idx i (0 - based)

// ---------- Type aliases ----------
using ll = long long;
using ull = unsigned long long;
using ld = long double;
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

// ---------- Constants ----------
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 998244353;

// ---------- Fast IO ----------
static const auto fastio = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}();

// ---------- Macros ----------
#define rv(a) \
  for (auto& x : (a)) cin >> x
#define pv(a)                                   \
  do {                                          \
    for (const auto& x : (a)) cout << x << ' '; \
    cout << '\n';                               \
  } while (0)
#define rm(mat)         \
  for (auto& r : (mat)) \
    for (auto& x : (r)) cin >> x
#define pm(mat)                                   \
  do {                                            \
    for (const auto& r : (mat)) {                 \
      for (const auto& x : (r)) cout << x << ' '; \
      cout << '\n';                               \
    }                                             \
  } while (0)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define pb push_back
#define eb emplace_back
#define rs resize
#define as assign
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define yno(a) cout << ((a) ? "YES\n" : "NO\n")
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define per(i, a, b) for (int i = (b) - 1; i >= (a); --i)
#define endl '\n'

const int mx = 1e6;
vi spf(mx + 1);

void buildSPF() {
  for (int i = 2; i <= mx; i++) {
    if (spf[i]) continue;

    spf[i] = i;

    for (ll j = 1LL * i * i; j <= mx; j += i)
      if (!spf[j]) spf[j] = i;
  }
}

vi getPrimeFact(int x) {
  vector<int> primes;

  while (x > 1) {
    int p = spf[x];

    primes.pb(p);

    while (x % p == 0) x /= p;
  }
  return primes;
}

// ---------- Solve ---------
void solve() {
  int n;
  cin >> n;

  vi a(n);
  rv(a);

  vll dp(n);
  vll cnt(1e6 + 1);

  dp[0] = 1;

  for(int i = 0; i < n; i++) {
    vi primes = getPrimeFact(a[i]);
    int m = primes.size();

    // Compute dp[i]
    for(int mask = 1; mask < (1 << m); mask++) {

      ll prod = 1;
      int bits = 0;

      for(int j = 0; j < m; j++) {
        if(mask & (1 << j)) {
          prod *= primes[j];
          bits++;
        }
      }

      if(bits & 1) // Odd
        dp[i] = (dp[i] + cnt[prod]) % MOD;
      else
        dp[i] = (dp[i] - cnt[prod] + MOD) % MOD;
    }

    // Insert current city
    for(int mask = 1; mask < (1 << m); mask++) {

      ll prod = 1;

      for(int j = 0; j < m; j++) {
        if(mask & (1 << j))
          prod *= primes[j];
      }

      cnt[prod] = (cnt[prod] + dp[i]) % MOD;
    }
  }

  cout << dp[n - 1] << '\n';
}

// ---------- Main ----------
int main() {
  buildSPF();
  solve();
  return 0;
}