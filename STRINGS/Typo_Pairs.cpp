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
#define YES cout << "Yes\n"
#define NO cout << "No\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define endl '\n'

/*
==========================



==========================
*/

void solve() {
  int n, m;
  cin >> n >> m;

  vs s(n);
  for (auto& x : s) cin >> x;

  ll c[3] = {0, 0, 0};

  for (int mask = 0; mask < (1 << m); mask++) {
    int cnt = __builtin_popcount(mask);

    if (cnt > 2) continue;

    vll keys(n);

    for (int i = 0; i < n; i++) {
      ll hash = 0;

      for (int j = 0; j < m; j++) {
        hash = hash * 27 + ((mask >> j & 1) ? 26 : s[i][j] - 'a');
      }

      keys[i] = hash;
    }

    sort(all(keys));

    for (int i = 0; i < n;) {
      int j = i;

      while (j < n && keys[j] == keys[i]) j++;

      ll L = j - i;

      c[cnt] += L * (L - 1) / 2;
      i = j;
    }
  }

  ll d0 = c[0];
  ll d1 = c[1] - m * d0;
  ll d2 = c[2] - (m - 1) * d1 - (ll)m * (m - 1) / 2 * d0;

  ll sum = d0 + d1 + d2;

  cout << sum << endl;
}

int main() {
  int t = 1;
  // cin >> t;

  while (t--) {
    solve();
  }
  return 0;
}