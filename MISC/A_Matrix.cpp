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

void solve() {
  ll a;
  cin >> a;

  string s;
  cin >> s;

  int n = (int)s.size();

  map<ll, ll> cnt;

  for (int i = 0; i < n; i++) {
    ll sum = 0;

    for (int j = i; j < n; j++) {
      sum += s[j] - '0';
      cnt[sum]++;
    }
  }

  ll ans = 0;

  if (a == 0) {
    ll total = n * (n + 1) / 2;
    ll zero = cnt[0];
    ans = zero * total + (total - zero) * zero;
  } else {
    for (ll x = 1; x * x <= a; x++) {
      if (a % x == 0) {
        ll y = a / x;
        ans += cnt[x] * cnt[y];

        if (x != y) {
          ans += cnt[y] * cnt[x];
        }
      }
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