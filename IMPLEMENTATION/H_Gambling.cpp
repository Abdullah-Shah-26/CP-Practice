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

void solve() {
  int n;
  cin >> n;

  vi x(n + 1);
  for (int i = 1; i <= n; i++) cin >> x[i];

  map<int, int> last, cur, start;

  int bestScore = 0, ansA = x[1], ansL = 1, ansR = 1;

  for (int i = 1; i <= n; i++) {
    int a = x[i];

    // First time
    if (last.find(a) == last.end()) {
      last[a] = i;
      cur[a] = 1;
      start[a] = i;
    }

    // Seen it before
    else {
      // a ... a -> gap = 4

      int gap = i - last[a];

      // Elements b/w = gap - 1
      // New a -> +1
      // score update = -(gap - 1) + 1
      //              = 2 - gap

      // Continue old interval
      // If extending the old interval gives a score at least as good as starting a new interval (1), continue it.
      // We choose it again & extend it
      if (cur[a] + 2 - gap >= 1) {
        cur[a] += (2 - gap);
      }

      // Start new one
      else {
        cur[a] = 1;
        start[a] = i;
      }

      last[a] = i;
    }

    if (bestScore < cur[a]) {
      bestScore = cur[a];
      ansA = a;
      ansL = start[a];
      ansR = i;
    }
  }

  cout << ansA << " " << ansL << " " << ansR << endl;
}

int main() {
  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}