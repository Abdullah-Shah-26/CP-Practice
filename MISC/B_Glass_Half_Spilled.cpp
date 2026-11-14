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

const int N = 100;
const int C = 10000;

int n;
int a[N + 5], b[N + 5];
int dp[N + 1][N + 1][C + 1];

// max water picking k glasses from i..n-1 with total cap as cap
int f(int i, int k, int cap) {
  if (k == 0) return cap == 0 ? 0 : -2;

  if (i == n) return -2;

  int& ans = dp[i][k][cap];

  if (ans != -1) return ans;

  ans = f(i + 1, k, cap);

  if (cap >= a[i]) {
    int t = f(i + 1, k - 1, cap - a[i]);

    if (t >= 0) ans = max(ans, t + b[i]);
  }

  return ans;
}

void solve() {
  cin >> n;

  int total = 0, maxCap = 0;

  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
    total += b[i];   // Total water available
    maxCap += a[i];  // Total capacity
  }

  memset(dp, -1, sizeof(dp));

  cout << fixed << setprecision(10);

  for (int k = 1; k <= n; k++) {
    double ans = 0.0;

    for (int cap = 0; cap <= maxCap; cap++) {
      int water = f(0, k, cap);

      if (water >= 0)
        ans = max(ans, min((double)cap, total / 2.0 + water / 2.0));
    }

    cout << ans << " ";
  }
}

int main() {
  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}