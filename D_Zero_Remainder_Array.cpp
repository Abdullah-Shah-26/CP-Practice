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
  ll n, k;
  cin >> n >> k;

  // freq[delta] = count of elements needing this exact condition to be
  // divisible by k

  map<ll, ll> freq;

  int cnt = 0;  // No of elements not div by k

  for (int i = 0; i < n; i++) {
    ll temp;
    cin >> temp;

    if (temp % k) {
      freq[k - temp % k]++;
      cnt++;
    }
  }

  if (cnt == 0) {
    cout << 0 << endl;
    return;
  }

  ll maxi = 0;  // max freq of particular delta
  ll rem = 0;

  for (auto [x, y] : freq) {
    if (maxi <= y) {
      maxi = y;
      rem = x;
    }
  }

  cout << 1LL * (maxi - 1) * k + rem + 1 << endl;
}

int main() {
  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}