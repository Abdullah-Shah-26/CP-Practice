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
  int n, k;
  cin >> n >> k;

  int pos[5][1001];
  vi perm;

  for (int p = 0; p < k; p++) {
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;

      if (p == 0) perm.push_back(x);
      pos[p][x] = i;
    }
  }

  // Longest subseq initially = 1

  vll dp(n + 1);
  for (int x = 1; x <= n; x++) dp[x] = 1;

  for (int i = 0; i < n; i++) {
    int y = perm[i];

    // IN all perm, pos of x must be before pos of y
    for (int x = 1; x <= n; x++) {
      bool valid = true;

      for (int p = 0; p < k; p++) {
        if (pos[p][x] >= pos[p][y]) {
          valid = false;
          break;
        }
      }

      // If we have already computed best LCS ending at x
      // Can we append y to it 
      if (valid) dp[y] = max(dp[y], dp[x] + 1);
    }
  }

  cout << *max_element(dp.begin() + 1, dp.end()) << endl;
}

int main() {
  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}