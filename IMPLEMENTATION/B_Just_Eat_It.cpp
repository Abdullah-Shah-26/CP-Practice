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

  vll a(n);
  rv(a);

  ll sum = accumulate(all(a), 0LL);

  ll maxSubarrSum = 0;
  ll curSum = 0;

  // We are choosing 2 different segments
  // Since Alice can't choose whole segment

  // Segment [0 ... n - 2]
  for (int i = 0; i < n - 1; i++) {
    curSum += a[i];

    if (curSum < 0) {
      curSum = 0;
    }

    maxSubarrSum = max(maxSubarrSum, curSum);
  }

  curSum = 0;

  // Segment [1 ... n - 1]
  for (int i = 1; i < n; i++) {
    curSum += a[i];

    if (curSum < 0) {
      curSum = 0;
    }

    maxSubarrSum = max(maxSubarrSum, curSum);
  }

  if (sum > maxSubarrSum)
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