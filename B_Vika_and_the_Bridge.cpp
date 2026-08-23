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
  int n, k;
  cin >> n >> k;

  vi c(n + 1);

  for (int i = 1; i <= n; i++) cin >> c[i];

  vi last(k + 1, 0);
  vi largest(k + 1, 0);
  vi secondLargest(k + 1, 0);

  // Two largest gaps for every color
  for (int i = 1; i <= n; i++) {
    int color = c[i];

    int gap = i - last[color] - 1;

    if (gap > largest[color]) {
      secondLargest[color] = largest[color];
      largest[color] = gap;
    } else if (gap > secondLargest[color]) {
      secondLargest[color] = gap;
    }

    last[color] = i;
  }

  // Handling gap from last occurence to end
  for (int color = 1; color <= k; color++) {
    if (last[color] == 0) continue;

    int gap = n - last[color];

    if (gap > largest[color]) {
      secondLargest[color] = largest[color];
      largest[color] = gap;
    } else if (gap > secondLargest[color]) {
      secondLargest[color] = gap;
    }
  }

  int ans = n;

  for (int color = 1; color <= k; color++) {
    if (last[color] == 0) continue;

    int candidate = max(largest[color] / 2, secondLargest[color]);

    ans = min(ans, candidate);
  }

  cout << ans << endl;

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