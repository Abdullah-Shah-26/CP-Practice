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

bool check(ll H, ll W, vpii& a) {
  // Sorted by ht, wt
  multiset<pii> byH, byW;

  for (auto [h, w] : a) {
    byH.insert({h, w});
    byW.insert({w, h});
  }

  while (!byH.empty()) {
    // Largest wt and ht among remaining
    auto itW = prev(byW.end());
    auto itH = prev(byH.end());

    // Block spans entire cur width
    // W = 5, block [3, 5]
    // Remove from both sets & decrease rem ht
    if (itW->first == W) {
      int h = itW->second;

      byW.erase(itW);
      byH.erase(byH.find({h, W}));

      H -= h;
    }

    // Block spans entire cur Ht
    // H = 4, block [4, 2]
    // Remove from both sets & dec rem wt
    else if (itH->first == H) {
      int w = itH->second;

      byH.erase(itH);
      byW.erase(byW.find({w, H}));

      W -= w;
    }

    // Neither peice can be removed
    else {
      return false;
    }
  }

  // All pieces removed
  // This rectangle can be formed
  return true;
}

void solve() {
  int n;
  cin >> n;

  vpii a(n);
  ll Area = 0;
  int maxH = 0, maxW = 0;

  for (int i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second;
    Area += 1LL * a[i].first * a[i].second;
    maxH = max(maxH, a[i].first);
    maxW = max(maxW, a[i].second);
  }

  vpll ans;

  if (Area % maxW == 0) {
    ll h = Area / maxW;
    if (check(h, maxW, a)) ans.pb({h, maxW});
  }

  if (Area % maxH == 0) {
    ll w = Area / maxH;
    if (check(maxH, w, a)) ans.pb({maxH, w});
  }

  sort(all(ans));
  ans.erase(unique(all(ans)), ans.end());

  cout << ans.size() << endl;
  for (auto [h, w] : ans) cout << h << " " << w << endl;

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