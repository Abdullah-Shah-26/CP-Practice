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



==========================
*/

vi c;
vvi adj;
bool ok;

vi dfs(int node) {
  vi res;

  for (auto nei : adj[node]) {
    vi sub = dfs(nei);

    if (!ok) return {};

    res.insert(res.end(), all(sub));
  }

  // If the no of nodes in the subtree of node < c[node] (The nodes that are
  // Supposed to have value < root of that subtree) Then ans is not possible

  if (c[node] > (int)res.size()) {
    ok = false;
    return {};
  }

  res.insert(res.begin() + c[node], node);

  return res;
}

void solve() {
  int n;
  cin >> n;

  adj.assign(n, {});
  c.assign(n, 0);

  int root = -1;

  for (int i = 0; i < n; i++) {
    int p, ci;
    cin >> p >> ci;

    c[i] = ci;

    if (p == 0)
      root = i;
    else
      adj[p - 1].pb(i);
  }

  ok = true;

  vi order = dfs(root);

  if (!ok) {
    cout << "NO" << endl;
    return;
  }

  cout << "YES" << endl;

  vi a(n);

  for (int i = 0; i < n; i++) a[order[i]] = i + 1;

  for (auto x : a) cout << x << " ";
  cout << endl;

  return;
}

int main() {
  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}