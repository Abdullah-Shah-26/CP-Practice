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
  int n;
  cin >> n;

  vpii segs(n);
  vi L(n), R(n);

  for (int i = 0; i < n; i++) {
    cin >> segs[i].first >> segs[i].second;
    L[i] = segs[i].first;
    R[i] = segs[i].second;
  }

  sort(all(L));
  sort(all(R));

  int ans = n;

  for (int i = 0; i < n; i++) {
    int l = segs[i].first;
    int r = segs[i].second;

    // Current segment [l,r]
    // Segments that dont intersect this have ri < l or li > r

    int dl = lower_bound(all(R), l) - begin(R);
    int dr = n - (upper_bound(all(L), r) - L.begin());

    // Total non intersecting intervals : dl + dr
    ans = min(ans, dl + dr);
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