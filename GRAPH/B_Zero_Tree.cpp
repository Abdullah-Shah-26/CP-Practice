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
const int N = 1e5 + 5;

vi adj[N];
ll v[N], needPlus[N], needMinus[N];

void dfs(int u, int p) {
  for (int c : adj[u]) {
    if (c == p) continue;

    dfs(c, u);

    // One op can cover several children at once, so take max, not sum.
    needPlus[u] = max(needPlus[u], needPlus[c]);
    needMinus[u] = max(needMinus[u], needMinus[c]);
  }

  ll x = v[u] + needPlus[u] - needMinus[u];

  // Fix the leftover with ops that stop at u.
  if (x > 0)
    needMinus[u] += x;
  else
    needPlus[u] += -x;
}

void solve() {
  int n;
  cin >> n;

  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].pb(b);
    adj[b].pb(a);
  }

  for (int i = 1; i <= n; i++) cin >> v[i];

  dfs(1, 0);

  cout << needPlus[1] + needMinus[1] << endl;
}

int main() {
  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}