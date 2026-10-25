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

const int N = 200001;

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
  ll m;
  cin >> m;

  vll cnt(N);

  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;
    cnt[x]++;
  }

  // distinct primes
  vi primes;
  for (int i = 2; i < N; i++) {
    if (cnt[i]) primes.pb(i);
  }

  int k = primes.size();

  vll pref(k + 1, 1), suff(k + 1, 1);

  for (int i = 0; i < k; i++)
    pref[i + 1] = pref[i] * (cnt[primes[i]] + 1) % (MOD - 1);

  for (int i = k - 1; i >= 0; i--)
    suff[i] = suff[i + 1] * (cnt[primes[i]] + 1) % (MOD - 1);

  ll ans = 1;

  for (int i = 0; i < k; i++) {
    ll e = cnt[primes[i]];
    ll sum = e * (e + 1) / 2;
    ll others = pref[i] * suff[i + 1] % (MOD - 1);
    ll totalCnt = sum % (MOD - 1) * others % (MOD - 1);
    ans = ans * binExpo(primes[i], totalCnt) % MOD;
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