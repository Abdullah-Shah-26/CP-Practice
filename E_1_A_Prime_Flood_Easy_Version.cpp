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

const int N = 3000;

int n;
vi cnt, pow2, pref;
vvi factors;
vvi dp;

int dfs(int l, int r) {
  if (l == r) return l;

  int& ans = dp[l][r];

  if (ans != -1) return ans;

  ans = 0;

  for (int p : factors[l]) {
    int nl = l - 1;
    int nr = r - (r % p == 0);

    ans = max(ans, dfs(nl, nr));
  }

  for (int p : factors[r]) {
    if (l % p == 0) continue;

    ans = max(ans, dfs(l, r - 1));
  }

  return ans;
}

void solve() {
  cin >> n;

  cnt.assign(n + 1, 0);

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    cnt[x]++;
  }

  pow2.assign(n + 1, 1);

  for (int i = 1; i <= n; i++) pow2[i] = 2LL * pow2[i - 1] % MOD;

  factors.assign(n + 1, {});
  pref.assign(n + 1, 0);

  for (int p = 2; p <= n; p++) {
    bool isPrime = true;

    for (int d = 2; d * d <= p; d++) {
      if (p % d == 0) {
        isPrime = false;
        break;
      }
    }

    if (!isPrime) continue;

    for (int x = p; x <= n; x += p) factors[x].pb(p);
  }

  dp.assign(n + 1, vi(n + 1, -1));

  for (int i = 1; i <= n; i++) pref[i] = pref[i - 1] + cnt[i];

  ll ans = 0;

  for (int l = 1; l <= n; l++) {
    for (int r = l; r <= n; r++) {
      if (cnt[l] == 0 || cnt[r] == 0) continue;

      ll ways;

      if (l == r) {
        ways = pow2[cnt[l]] - 1;
      } else {
        int mid = pref[r - 1] - pref[l];

        ways = 1LL * (pow2[cnt[l]] - 1) * (pow2[cnt[r]] - 1) % MOD;

        ways = ways * pow2[mid] % MOD;
      }

      ans = (ans + ways * dfs(l, r)) % MOD;
    }
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