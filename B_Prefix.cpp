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

5
3 -5 1 -4 2

==========================
*/

void solve() {
  int n;
  cin >> n;

  vll a(n);
  rv(a);

  ll maxElem = a[0];
  ll minSum = a[0];
  ll maxSum = a[0];

  for (int i = 1; i < n; i++) {
    ll x = a[i];

    maxElem = max({maxElem, x, x + maxSum, x - minSum});

    // ai -> ai, ai + s, ai + 2*s
    ll nxtMin = min({x, minSum + x, 2 * minSum + x});
    ll nxtMax = max({x, maxSum + x, 2 * maxSum + x});

    minSum = nxtMin;
    maxSum = nxtMax;
  }

  cout << maxElem << endl;

  return;
}

int main() {
  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}