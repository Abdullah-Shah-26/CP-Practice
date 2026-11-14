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

const int N = 500005;

vector<int> adj[N];
int mark[N];

void solve() {
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    adj[u].pb(v);
    adj[v].pb(u);
  }

  vector<int> rem(n);
  iota(all(rem), 0);
  vector<vector<int>> ans;

  while (!rem.empty()) {
    int s = rem.back();
    rem.pop_back();
    vector<int> comp = {s};

    // comp doubles as the BFS queue
    for (int i = 0; i < (int)comp.size(); i++) {
      int u = comp[i];

      // Marking unallowed edges from u
      for (int v : adj[u]) mark[v] = u + 1;

      vector<int> keep;
      for (int v : rem) {
        if (mark[v] == u + 1)
          keep.pb(v);
        else  // From the rem u can visit these
          comp.pb(v);
      }

      swap(rem, keep);
    }
    ans.pb(comp);
  }

  cout << ans.size() << endl;
  for (auto& vec : ans) {
    cout << vec.size() << " ";
    for (int x : vec) cout << x + 1 << " ";
    cout << endl;
  }
}

int main() {
  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}