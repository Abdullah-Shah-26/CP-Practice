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
  int n;
  cin >> n;

  // first div * last divisor = x

  vll d(n);
  for (int i = 0; i < n; i++) cin >> d[i];

  sort(all(d));

  ll x = d[0] * d[n - 1];

  vll divisors;
  for (ll i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      divisors.pb(i);

      if (i != x / i) divisors.pb(x / i);
    }
  }

  sort(all(divisors));

  // for (auto x : d) cout << x << " ";
  // cout << endl;
  // for (auto x : divisors) cout << x << " ";
  // cout << endl;

  if(divisors == d) cout << x << endl;
  else cout << -1 << endl;
}

int main() {
  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}