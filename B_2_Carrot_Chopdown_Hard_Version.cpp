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

void solve() {
  ll n, m;
  cin >> n >> m;

  vll cnt(m + 1);

  for (int i = 0; i < n; i++) {
    ll x;
    cin >> x;

    cnt[x]++;
  }

  vll pref(m + 1);

  for (int i = 1; i <= m; i++) {
    pref[i] = pref[i - 1] + cnt[i];
  }

  auto getCnt = [&](ll x) {
    if (x > m) return 0LL;

    return n - pref[x - 1];
  };

  // Max pieces of sz = v if INF ops
  vll s(m + 1);

  ll maxs = 0;

  for (int v = 1; v <= m; v++) {
    for (int c = 1; c * v <= m; c++) {
      s[v] += getCnt(c * v); 
    }

    maxs = max(maxs, s[v]);
  }

  vll ans(m + 1);

  for (int k = 1; k <= m; k++) {
    if ((1 << k) > m || k >= 20) {
      ans[k] = maxs;
      continue;
    }

    int p = 1 << k;
    ll cur = 0;

    for (int v = 1; v <= m; v++) {
      if (p > m / v) {
        cur = max(cur, s[v]);
      } else {
        ll score = cnt[p * v];

        for (int c = 1; c < p; c++) score += getCnt(c * v);

        cur = max(cur, score);
      }
    }

    ans[k] = cur;
  }

  for (int k = 1; k <= m; k++) {
    cout << ans[k] << " ";
  }
  cout << "\n";
}

int main() {
  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}