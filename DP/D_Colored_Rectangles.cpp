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

ll r, g, b;
vll R, G, B;

ll dp[201][201][201];

ll f(int i, int j, int k) {
  // Only 1 color available - cannot pair up
  if ((i == r && j == g) || (i == r && k == b) || (j == g && k == b)) return 0;

  ll& ans = dp[i][j][k];

  if (ans != -1) return ans;

  ans = 0;

  // red and green
  if (i < r && j < g) ans = max(ans, R[i] * G[j] + f(i + 1, j + 1, k));

  // red and blue
  if (i < r && k < b) ans = max(ans, R[i] * B[k] + f(i + 1, j, k + 1));

  // green and blue
  if (j < g && k < b) ans = max(ans, G[j] * B[k] + f(i, j + 1, k + 1));

  return ans;
}

void solve() {
  cin >> r >> g >> b;

  R.resize(r);
  G.resize(g);
  B.resize(b);

  for (int i = 0; i < r; i++) cin >> R[i];
  for (int i = 0; i < g; i++) cin >> G[i];
  for (int i = 0; i < b; i++) cin >> B[i];

  // Necessary 
  // So recursion consumes larger remaining first 
  sort(rall(R));
  sort(rall(G));
  sort(rall(B));

  memset(dp, -1, sizeof(dp));

  cout << f(0, 0, 0) << endl;
}

int main() {
  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}