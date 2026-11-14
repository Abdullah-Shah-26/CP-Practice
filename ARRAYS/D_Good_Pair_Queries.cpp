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
  ll n, q;
  cin >> n >> q;

  vvll pref(n + 2, vll(4, 0));

  string s, t;
  cin >> s >> t;

  for (int i = 0; i < n; i++) {
    pref[i + 1] = pref[i];

    if (s[i] == '0' && t[i] == '0') pref[i + 1][0]++;
    if (s[i] == '0' && t[i] == '1') pref[i + 1][1]++;
    if (s[i] == '1' && t[i] == '0') pref[i + 1][2]++;
    if (s[i] == '1' && t[i] == '1') pref[i + 1][3]++;
  }

  while (q--) {
    int l, r;
    cin >> l >> r;

    ll cnt00 = pref[r][0] - pref[l - 1][0];
    ll cnt01 = pref[r][1] - pref[l - 1][1];
    ll cnt10 = pref[r][2] - pref[l - 1][2];
    ll cnt11 = pref[r][3] - pref[l - 1][3];

    ll rem = abs(cnt01 - cnt10);

    if (cnt00 + cnt11 >= rem)
      YES;
    else
      NO;
  }
}

int main() {
  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}