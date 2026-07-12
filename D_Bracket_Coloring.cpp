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

  string s;
  cin >> s;

  int bal[n];
  if (s[0] == '(')
    bal[0] = 1;
  else
    bal[0] = -1;

  for (int i = 1; i < n; i++) {
    if (s[i] == ')')
      bal[i] = bal[i - 1] - 1;
    else
      bal[i] = bal[i - 1] + 1;
  }

  if (bal[n - 1] != 0) {
    pf(-1);
    return;
  }

  if (*min_element(bal, bal + n) == 0 || *max_element(bal, bal + n) == 0) {
    pf(1);

    for (int i = 0; i < n; i++) cout << 1 << " ";

    cout << endl;
    return;
  }

  vi ans(n);
  rep(i, 0, n) {
    if (bal[i] > 0)
      ans[i] = 1;
    else if (bal[i] < 0)
      ans[i] = 2;
    else
      ans[i] = (bal[i - 1] > 0) ? 1 : 2;
  }

  pf(2);
  pv(ans);
  return;
}

int main() {
  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}