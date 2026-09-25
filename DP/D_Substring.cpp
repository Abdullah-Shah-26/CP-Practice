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
const ll LINF = 4e18;
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

dp[u][c] = For each char c, what is the max cnt of c's on path ending at node u

==========================
*/

void solve() {
  int n, m;
  cin >> n >> m;

  string s;
  cin >> s;

  vvi adj(n + 1);
  vi indeg(n + 1, 0);

  vector<array<int, 26>> dp(n + 1);

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;

    indeg[v]++;
    adj[u].pb(v);
  }

  queue<int> q;

  for (int u = 1; u <= n; u++) {
    // If we start at this node, we already have this char once
    dp[u][s[u - 1] - 'a'] = 1;

    if (indeg[u] == 0) {
      q.push(u);
    }
  }

  int ans = 0;
  int cnt = 0;

  while (!q.empty()) {
    int u = q.front();
    q.pop();

    // processed
    cnt++;

    for(int c = 0; c < 26; c++)
      ans = max(ans, dp[u][c]);

    for (int v : adj[u]) {
      
      for(int c = 0; c < 26; c++)
        dp[v][c] = max(dp[v][c], dp[u][c] + (s[v - 1] - 'a' == c));

      indeg[v]--;

      if (indeg[v] == 0) {
        q.push(v);
      }
    }
  }

  if (cnt != n) {
    cout << -1 << endl;
    return;
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