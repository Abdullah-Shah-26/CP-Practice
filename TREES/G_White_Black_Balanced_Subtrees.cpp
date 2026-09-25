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
const ll LINF = 1e18;
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

sum[u] = W - B in subtree of u

==========================
*/

void solve() {
  int n;
  cin >> n;

  vvi adj(n + 1);

  for (int i = 2; i <= n; i++) {
    int p;
    cin >> p;

    adj[p].pb(i);
  }

  string s;
  cin >> s;

  vi sum(n + 1);

  int ans = 0;

  function<void(int)> dfs = [&](int u) {
    sum[u] = (s[u - 1] == 'W' ? 1 : -1);

    for (int v : adj[u]) {
      dfs(v);
      sum[u] += sum[v];
    }

    if (sum[u] == 0) ans++;
  };

  dfs(1);

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