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

  vll v(n);
  rv(v);

  vll temp = v;
  sort(all(temp));

  vll pref1(n + 1), pref2(n + 1);

  for (int i = 0; i < n; i++) {
    pref1[i + 1] = pref1[i] + v[i];
    pref2[i + 1] = pref2[i] + temp[i];
  }

  int m;
  cin >> m;

  while (m--) {
    int t;
    cin >> t;

    if (t == 1) {
      int l, r;
      cin >> l >> r;

      cout << pref1[r] - pref1[l - 1] << endl;
    } else {
      int l, r;
      cin >> l >> r;

      cout << pref2[r] - pref2[l - 1] << endl;
    }
  }
}

int main() {
  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}