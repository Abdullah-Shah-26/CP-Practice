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

ll LCM(ll a, ll b, ll c) {
  ll l = lcm(a, b);
  return lcm(l, c);
}

void solve() {
  ll n;
  cin >> n;

  if(n <= 2){
     cout << n << endl;
     return;
  }

  if ((n & 1))
    cout << LCM(n, n - 1, n - 2) << endl;
  else {
    ll ans = 0;

    for (ll a = max(1LL, n - 50); a <= n; a++) {
      for (ll b = a; b <= n; b++) {
        for (ll c = b; c <= n; c++) {
          ans = max(ans, LCM(a, b, c));
        }
      }
    }

    cout << ans << endl;
  }
}

int main() {
  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}