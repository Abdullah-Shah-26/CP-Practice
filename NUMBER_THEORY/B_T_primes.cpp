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

bool isPrime[1000001];

void sieve() {
  fill(isPrime, isPrime + 1000001, true);

  isPrime[0] = isPrime[1] = false;

  for (int i = 2; i * i <= 1000000; i++) {
    if (isPrime[i]) {

      // Marking all the multiples of i as non prime
      for (int j = i * i; j <= 1000000; j+=i) {
        isPrime[j] = false;
      }
    }
  }
}

bool f(ll x) {
  // x must be a perfect square
  // r must be a prime no
  // This ensures that x has exactly 3 distinct prime factors
  // Ex : 9 - {1, 3, 9}
  //    : 25 - {1, 5, 25}

  ll r = sqrt(x);

  if (r * r != x) return false;

  return isPrime[r];
}

void solve() {
  int n;
  cin >> n;

  vll x(n);
  rv(x);

  sieve();

  for (ll X : x) {
    if (f(X))
      YES;
    else
      NO;
  }
}

int main() {
  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}