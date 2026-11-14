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
  int n, k;
  cin >> n >> k;

  vi a(n);
  int m = INF, maxA = 0;

  for (int& x : a) {
    cin >> x;
    m = min(m, x);
    maxA = max(maxA, x);
  }

  vi freq(maxA + 1, 0);

  for (int x : a) freq[x]++;

  vi pref(maxA + 1, 0);

  if (m - 1 <= k) {
    cout << m << endl;
    return;
  }

  for (int i = 1; i <= maxA; i++) pref[i] = pref[i - 1] + freq[i];

  for (int d = m; d - 1 > k; d--) {
    int cnt = 0;

    for (int l = d; l <= maxA; l += d) {
      int r = min(l + k, maxA);
      cnt += pref[r] - pref[l - 1];
    }

    if (cnt == n) {
      cout << d << endl;
      return;
    }
  }

  cout << k + 1 << endl;
}

int main() {
  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}