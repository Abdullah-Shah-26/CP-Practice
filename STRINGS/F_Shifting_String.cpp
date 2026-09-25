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



==========================
*/

ll lcm(ll a, ll b) { return a / __gcd(a, b) * b; }

void solve() {
  int n;
  cin >> n;

  string s;
  cin >> s;

  ll ans = 1;

  vector<ll> perm(n);
  for (int i = 0; i < n; i++) {
    cin >> perm[i];
    perm[i]--;  // Converting to 0 based
  }

  vb vis(n, false);

  for (int i = 0; i < n; i++) {
    if (vis[i]) continue;

    vi cycle;

    int cur = i;

    while (!vis[cur]) {
      vis[cur] = true;

      cycle.pb(cur);

      cur = perm[cur];
    }

    string x;

    for (int pos : cycle) {
      x += s[pos];
    }

    int len = x.size();

    for (int k = 1; k <= len; k++) {
      bool flag = true;

      for (int i = 0; i < len; i++) {
        if (x[i] != x[(i + k) % len]) {
          flag = false;
          break;
        }
      }

      if (flag) {  // Smallest - First valid k for this cycle
        ans = lcm(ll(k), ans);
        break;
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