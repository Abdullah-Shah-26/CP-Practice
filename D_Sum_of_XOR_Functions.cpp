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
const int B = 31;

void solve() {
  int n;
  cin >> n;

  vi a(n);
  rv(a);

  ll ans = 0;

  for (int bit = 0; bit < 31; bit++) {
    ll oneLen = 0;
    ll zeroLen = 0;

    ll oneCnt = 0;
    ll zeroCnt = 0;

    for (int i = 0; i < n; i++) {
      oneLen += oneCnt;
      zeroLen += zeroCnt;

      // Xor flips bit
      if (a[i] & (1 << bit)) {
        swap(oneLen, zeroLen);
        swap(oneCnt, zeroCnt);

        oneLen = (oneLen + 1) % MOD;
        oneCnt++;
      } else {
        zeroLen = (zeroLen + 1) % MOD;
        zeroCnt++;
      }

      ans = (ans + oneLen * (1LL << bit)) % MOD;
    }
  }

  cout << ans << endl;
}

int main() {
  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}