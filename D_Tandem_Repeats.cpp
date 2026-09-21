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

void solve() {
  string s;
  cin >> s;

  int n = s.size();
  int ans = 0;

  for (int d = 1; d <= n / 2; d++) {
    int l = 0;
    int r = 2 * d - 1;

    int cnt = 0;

    // Initial window [l..r]

    for (int i = 0; i < d; i++) {
      if (s[l + i] == s[l + i + d] || s[l + i] == '?' || s[l + i + d] == '?')
        cnt++;
    }

    if (cnt == d) ans = max(ans, 2 * d);

    // [l..r] -> [l+1..r+1]
    while (r + 1 < n) {
      if (s[l] == '?' || s[l + d] == '?' || s[l] == s[l + d]) cnt--;

      if (s[l + d] == '?' || s[r + 1] == '?' || s[l + d] == s[r + 1]) cnt++;

      l++;
      r++;

      if (cnt == d) ans = max(ans, 2 * d);
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