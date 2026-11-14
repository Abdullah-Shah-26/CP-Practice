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

int row[4] = {0, 0, -1, 1};
int col[4] = {1, -1, 0, 0};

int n, m;
int a[1001][1001];
int vis[1001][1001];

int dfs(int i, int j) {
  vis[i][j] = 1;

  int sum = a[i][j];

  for (int k = 0; k < 4; k++) {
    int ni = i + row[k];
    int nj = j + col[k];

    if (ni >= 0 && ni < n && nj >= 0 && nj < m && a[ni][nj] > 0 && !vis[ni][nj])
      sum += dfs(ni, nj);
  }

  return sum;
}

void solve() {
  cin >> n >> m;

  for (int i = 0; i < 1001; i++) {
    for (int j = 0; j < 1001; j++) {
      vis[i][j] = 0;
    }
  }

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> a[i][j];

  int ans = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] > 0 && !vis[i][j]) {
        ans = max(ans, dfs(i, j));
      }
    }
  }

  cout << ans << endl;
}

int main() {
  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}