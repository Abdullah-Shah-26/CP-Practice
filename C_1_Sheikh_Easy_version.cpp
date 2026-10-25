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
  int n, q;
  cin >> n >> q;

  vll v(n), pref(n), xorr(n);

  for (int i = 0; i < n; i++) {
    cin >> v[i];

    pref[i] = (i ? pref[i - 1] : 0) + v[i];
    xorr[i] = (i ? xorr[i - 1] : 0) ^ v[i];
  }

  auto getCost = [&](int l, int r) -> ll {
    ll sum = pref[r] - (l ? pref[l - 1] : 0);
    int xr = xorr[r] ^ (l ? xorr[l - 1] : 0);
    return sum - xr;
  };

  // Initally ans has max possible cost 
  ll ans = pref.back() - xorr.back();
  int l = 0, r = n - 1;

  while (q--) {
    int L, R;
    cin >> L >> R;
    L--;
    R--;

    if (ans == 0) {
      cout << 1 << " " << 1 << endl;
      return;
    }

    ll target = getCost(L, R);
    int ansL = L, ansR = R;
    l = L;

    for (int r = L; r <= R; r++) {
      // Shrink window until it becomes invalid
      while (l < r && getCost(l, r) == target) {
        if (r - l < ansR - ansL) {
          ansR = r;
          ansL = l;
        }
        l++;
      }
    }

    cout << ansL + 1 << " " << ansR + 1 << endl;
  }

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