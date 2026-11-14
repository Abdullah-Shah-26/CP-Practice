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
const int MOD = 100000000;

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

n1 = footmen
n2 = horsemen

no more than k1 consecutive footmen
no more than k2 consecutive horsemen

no of beautiful arrangements

==========================
*/
ll n1, n2, k1, k2;

// 1 = footmen
// 2 = horsemen

ll dp[101][101][3][11];

ll f(int i, int j, int last, int cnt) {
  if (i == n1 && j == n2) return 1;

  ll& ans = dp[i][j][last][cnt];

  if (ans != -1) return ans;

  ans = 0;

  if (i < n1 && (last != 1 || cnt < k1)) {
    ans = (ans + f(i + 1, j, 1, last == 1 ? cnt + 1 : 1)) % MOD;
  }

  if (j < n2 && (last != 2 || cnt < k2)) {
    ans = (ans + f(i, j + 1, 2, last == 2 ? cnt + 1 : 1)) % MOD;
  }

  return ans;
}

void solve() {
  cin >> n1 >> n2 >> k1 >> k2;

  memset(dp, -1, sizeof(dp));

  cout << f(0, 0, 0, 0) << endl;
}

int main() {
  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}