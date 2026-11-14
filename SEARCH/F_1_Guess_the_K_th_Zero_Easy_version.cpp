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

/*
==========================



==========================
*/

int query(int l, int r) {
  cout << "? " << l << " " << r << endl;

  int res;
  cin >> res;

  if (res == -1) exit(0);

  return res;
}

void solve() {
  int n, t;
  cin >> n >> t;

  while (t--) {
    int k;
    cin >> k;

    int low = 1, high = n, ans = -1;

    while (low <= high) {
      int mid = low + (high - low) / 2;

      int ones = query(1, mid);
      int zeros = mid - ones;

      if (zeros >= k) {
        ans = mid;
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }

    cout << "! " << ans << endl;
  }
}

int main() {
  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}