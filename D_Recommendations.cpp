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

void solve() {
  int n;
  cin >> n;

  vpll Lorder(n);
  for (int i = 0; i < n; i++) cin >> Lorder[i].first >> Lorder[i].second;

  map<pll, int> m;
  for (int i = 0; i < n; i++) m[Lorder[i]] = i;

  // L by asc
  // If L is equal
  // R by desc
  sort(all(Lorder), [](auto& a, auto& b) {
    if (a.first != b.first) return a.first < b.first;

    return a.second > b.second;
  });

  vpll Rorder = Lorder;

  // R by desc
  // If R is same
  // L by asc
  sort(all(Rorder), [](auto& a, auto& b) {
    if (a.second != b.second) return a.second > b.second;

    return a.first < b.first;
  });

  vll ansL(n, 0), ansR(n, 0);

  set<ll> setL, setR;

  //         Li-----------Ri
  //  Lj--------------------------Rj
  // Ans = (Li - Lj) + (Rj - Ri)

  for (int i = 0; i < n; i++) {
    auto [L, R] = Lorder[i];
    auto it = setR.lower_bound(R);

    // Among seen intervals whose Lj <= Li
    // Find the smallest Rj >= Ri
    if (it != setR.end()) ansL[m[{L, R}]] = *it - R;

    setR.insert(R);
  }

  for (int i = 0; i < n; i++) {
    auto [L, R] = Rorder[i];
    auto it = setL.upper_bound(L);

    // Among seen intervals whose Rj >= Ri
    // Find the largest Lj <= Li
    if (it != setL.begin()) {
      it--;
      ansR[m[{L, R}]] = L - *it;
    }

    setL.insert(L);
  }

  for (int i = 0; i < n; i++) cout << ansL[i] + ansR[i] << endl;
}

int main() {
  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}