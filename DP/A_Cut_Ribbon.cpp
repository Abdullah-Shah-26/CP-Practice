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

int dp[4001];
int a, b, c;

int f(int n) {
  if (n == 0) return 0;
  if (n < 0) return -INF;

  if (dp[n] != -1) return dp[n];

  int takeA = 1 + f(n - a);
  int takeB = 1 + f(n - b);
  int takeC = 1 + f(n - c);

  return dp[n] = max({takeA, takeB, takeC});
}

void solve() {
  int n;
  cin >> n >> a >> b >> c;

  memset(dp, -1, sizeof(dp));

  cout << f(n) << endl;
}

int main() {
  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}