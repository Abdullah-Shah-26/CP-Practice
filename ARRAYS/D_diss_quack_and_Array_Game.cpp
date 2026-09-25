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
const ll N = (1 << 20) + 5;

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

ll solo[N + 1];
ll minC[21][100005];

void precompute() {
  solo[1] = 1;

  for (int i = 2; i <= N; i++)
    if (i & 1)
      solo[i] = 1 + solo[i - 1];
    else
      solo[i] = 1 + solo[i >> 1];

  for (ll m = 0; m <= 20; m++) {
    ll s = 1LL << m;
    ll mini = LINF;

    for (ll y = N; y >= 1; y--) {
      if (y % s == 0 && solo[y] + y < mini) mini = solo[y] + y;

      if (y <= 100000) minC[m][y] = mini;
    }
  }
}

void solve() {
  ll n;
  cin >> n;

  vll a(n);

  ll sum = 0;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }

  ll ans = LINF;

  for (int m = 0; m <= 20; m++) {
    ll cur = 0;

    for (int i = 0; i < n; i++) cur += minC[m][a[i]];

    ll cost = cur - sum - (n - 1) * 1LL * m;

    if (cost < ans) ans = cost;
  }

  pf(ans);
}

int main() {
  precompute();

  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}