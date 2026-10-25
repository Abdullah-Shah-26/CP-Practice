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
  int n, p;
  cin >> n >> p;

  p--;

  string s;
  cin >> s;

  // P can at max be last idx of left half
  if (p >= n / 2) p = n - p - 1;

  int ans = 0, left = -1, right = -1;

  for (int i = 0; i < n / 2; i++) {
    int d = abs(s[i] - s[n - i - 1]);

    if (d == 0) continue;

    ans += min(d, 26 - d);

    // First mismatch
    if (left == -1) left = i;

    // Last mismatch
    right = i;
  }

  // First move P to a [l,r] any one which is closer
  if (left != -1) {
    ans += min(abs(p - left), abs(p - right));

    // Then we traverse L-R or R-L
    ans += (right - left);
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