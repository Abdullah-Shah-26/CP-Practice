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
#define pf(x) cout << x << '\n'
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
  int n;
  cin >> n;

  vector<vector<pii>> adj(n + 1);

  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].pb({v, i});
    adj[v].pb({u, i});
  }

  vi ans(n - 1, -1);

  int k = 0;
  for (int i = 1; i <= n; i++) {
    if (adj[i].size() >= 3) {  // Not a pipe
      ans[adj[i][0].second] = 0;
      ans[adj[i][1].second] = 1;
      ans[adj[i][2].second] = 2;
      k = 3;
      break;
    }
  }

  for (int i = 0; i < n - 1; i++) {
    if (ans[i] == -1) {
      ans[i] = k;
      k++;
    }
  }

  for (auto x : ans) cout << x << endl;
}

int main() {
  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}