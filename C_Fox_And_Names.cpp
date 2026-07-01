#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
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
#define rm(mat)         \
  for (auto& r : (mat)) \
    for (auto& x : (r)) cin >> x
#define pm(mat)                                   \
  do {                                            \
    for (const auto& r : (mat)) {                 \
      for (const auto& x : (r)) cout << x << ' '; \
      cout << '\n';                               \
    }                                             \
  } while (0)
#define pf(x) cout << x << '\n'
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define pb push_back
#define eb emplace_back
#define rs resize
#define as assign
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define yno(a) cout << ((a) ? "YES\n" : "NO\n")
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define per(i, a, b) for (int i = (b) - 1; i >= (a); --i)
#define endl '\n'

void solve() {
  int n;
  cin >> n;

  vs names(n);
  for (int i = 0; i < n; i++) cin >> names[i];

  // Topo req DAG
  vi adj[26];
  vi indeg(26, 0);

  for (int i = 0; i < n - 1; i++) {
    string& s1 = names[i];
    string& s2 = names[i + 1];

    // comparing 2 adj strings
    int len = min(s1.size(), s2.size());
    bool diff = false;

    for (int j = 0; j < len; j++) {
      if (s1[j] != s2[j]) {
        // we got an edge u->v where u should be before v
        int u = s1[j] - 'a';
        int v = s2[j] - 'a';

        adj[u].pb(v);
        indeg[v]++;
        diff = true;
        break;
      }
    }

    // In lexico order, longer word can never appear before shorter one
    if (!diff && s1.size() > s2.size()) {
      pf("Impossible");
      return;
    }
  }

  queue<int> q;
  for (int i = 0; i < 26; i++) {
    if (indeg[i] == 0) {
      q.push(i);
    }
  }

  string ans = "";

  while (!q.empty()) {
    int u = q.front();
    q.pop();

    ans += char(u + 'a');

    for (int v : adj[u]) {
      indeg[v]--;

      if (indeg[v] == 0) {
        q.push(v);
      }
    }
  }

  // we need to output any perm of chars 'a'-'z'
  if (ans.size() == 26)
    pf(ans);
  else
    pf("Impossible");
}

int main() {
  solve();
  return 0;
}