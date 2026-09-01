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

  vi a(n + 1);
  for (int i = 1; i <= n; i++) cin >> a[i];

  vll next(n + 1, -1);

  for (int i = n - 1; i >= 1; i--) {
    if (a[i] != a[i + 1])
      next[i] = i + 1;
    else
      next[i] = next[i + 1];
  }

  int q;
  cin >> q;

  while (q--) {
    int l, r;
    cin >> l >> r;

    if (next[l] != -1 && next[l] <= r)
      cout << l << " " << next[l] << endl;
    else
      cout << -1 << " " << -1 << endl;
  }

  cout << endl;
}

int main() {
  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}