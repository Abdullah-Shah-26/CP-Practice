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

const int N = 300;
bool isPrime[N + 1];

void sieve() {
  fill(isPrime, isPrime + N + 1, true);
  isPrime[0] = isPrime[1] = false;

  for (int i = 2; i * i <= N; i++) {
    if (isPrime[i]) {
      for (int j = i * i; j <= N; j += i) {
        isPrime[j] = false;
      }
    }
  }
}

bool checkPrime(int n) {
  if (n < 2) return false;

  for (int i = 2; i * i <= n; i++)
    if (n % i == 0) return false;

  return true;
}

void solve() {
  int n;
  cin >> n;

  if (checkPrime(n)) {
    cout << 1 << endl;  // cnt
    cout << n << endl;
    return;
  }

  // Largest prime no < n
  int p = n - 1;

  while (!checkPrime(p)) p--;

  int x = n - p;  // difference b/w prime <= 281

  // Cannot split 2 into 2 primes
  if (x == 2) {
    cout << 2 << endl;
    cout << 2 << " " << p << endl;
    return;
  }

  // Need a + b = x, where a, b == prime

  for (int a = 2; a <= x; a++) {
    int b = x - a;

    if (isPrime[a] && isPrime[b]) {
      cout << 3 << endl;
      cout << a << " " << b << " " << p << endl;
      return;
    }
  }
}

int main() {
  sieve();

  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}