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

const int M = 10000000;

void solve() {
  int n;
  cin >> n;

  vi freq(M + 1), f(M + 1), pref(M + 1);
  vb isPrime(M + 1, true);

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    freq[x]++;
  }

  isPrime[0] = isPrime[1] = false;
  for (int i = 2; i * i <= M; i++) {
    if (!isPrime[i]) continue;

    // If i = prime
    // Mark all multiples of i as not prime
    for (int j = i * i; j <= M; j += i) {
      isPrime[j] = false;
    }
  }

  for (int p = 2; p <= M; p++) {
    if (isPrime[p]) {
      // Visiit all the multiples of prime p
      for (int j = p; j <= M; j += p) {
        f[p] += freq[j];
      }
    }
  }

  for (int i = 2; i <= M; i++) {
    pref[i] = pref[i - 1] + (isPrime[i] ? f[i] : 0);
  }

  int m;
  cin >> m;
  while (m--) {
    int l, r;
    cin >> l >> r;

    if (l > M) {
      cout << 0 << endl;
      continue;
    }

    r = min(r, M);
    cout << pref[r] - pref[l - 1] << endl;
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