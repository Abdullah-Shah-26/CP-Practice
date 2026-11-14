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

1 + 1 = 2
o + o = even
e + e = even

For odd sum :
1 + 2 = 3
o + e

4 + 3 = 7
e + o

==========================
*/

void solve() {
  ll n, x;
  cin >> n >> x;

  ll odd = 0, even = 0;
  for (int i = 0; i < n; i++) {
    ll a;
    cin >> a;

    if (a & 1)
      odd++;
    else
      even++;
  }

  bool valid = false;

  // If at any moment i have odd no of odds and even no of evens then we can make odd sum
  for (int i = 1; i <= x; i += 2) {
    if (odd >= i && even >= x - i) {
      valid = true;
      break;
    }
  }

  if (valid)
    YES;
  else
    NO;

}

int main() {
  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}