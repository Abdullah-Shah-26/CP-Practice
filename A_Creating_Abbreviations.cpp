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
  ll n, m;
  cin >> n >> m;

  vs w(n), a(m);
  vb have(26, false);

  for (auto& s : w) {
    cin >> s;
    have[s[0] - 'a'] = true;
  }

  for (auto& s : a) cin >> s;

  ll made = 0;

  while (1) {
    bool found = false;

    for (int i = 0; i < m; i++) {
      if (a[i] == "")  // already created
        continue;

      bool can = true;

      for (char& ch : a[i]) {
        if (!have[ch - 'A']) {
          can = false;
          break;
        }
      }

      if (can) {
        // abbr created
        // This abbr becomes word

        have[a[i][0] - 'A'] = true;

        a[i] = "";
        made++;
        found = true;
      }
    }

    if (!found) break;
  }

  if (made == m)
    YES;
  else
    NO;
}

int main() {
  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}