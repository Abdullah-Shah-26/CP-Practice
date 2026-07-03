#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

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
#define pf(x) cout << x << '\n'
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

class SPF {
 public:
  vector<int> spf;

  SPF(int n) {
    spf.resize(n + 1);

    for (int i = 0; i <= n; i++) spf[i] = i;

    for (int i = 2; i * i <= n; i++) {
      if (spf[i] != i) continue;

      for (int j = i * i; j <= n; j += i) {
        if (spf[j] == j) spf[j] = i;
      }
    }
  }

  vector<int> primeFactors(int x) {
    vector<int> factors;

    while (x > 1) {
      factors.push_back(spf[x]);
      x /= spf[x];
    }

    return factors;
  }

  vector<pair<int, int>> primeFactorFreq(int x) {
    vector<pair<int, int>> factors;

    while (x > 1) {
      int prime = spf[x];
      int cnt = 0;

      while (x > 1 && spf[x] == prime) {
        cnt++;
        x /= prime;
      }

      factors.push_back({prime, cnt});
    }

    return factors;
  }

  int omega(int x) { return primeFactorFreq(x).size(); }

  int Omega(int x) {
    int cnt = 0;

    while (x > 1) {
      cnt++;
      x /= spf[x];
    }

    return cnt;
  }

  pair<int, int> omegaOmega(int x) {
    int distinct = 0;
    int total = 0;

    while (x > 1) {
      int prime = spf[x];
      distinct++;

      while (x > 1 && spf[x] == prime) {
        total++;
        x /= prime;
      }
    }

    return {distinct, total};
  }
};

SPF sieve(1000000);

void solve() {
  int n;
  cin >> n;
  auto [omegaCnt, OmegaCnt] = sieve.omegaOmega(n);
  pf(omegaCnt + OmegaCnt - 1);
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}