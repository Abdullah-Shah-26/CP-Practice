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
  ll n, m, k;
  cin >> n >> m >> k;

  vll a(n + 1);
  for (int i = 1; i <= n; i++) cin >> a[i];

  vector<T> ops(m);

  for (auto& [l, r, d] : ops) cin >> l >> r >> d;

  vpll queries(k);

  vll diff(m + 2, 0);

  for (auto& [l, r] : queries) {
    cin >> l >> r;
    diff[l]++;
    diff[r + 1]--;
  }

  // diff now stores the no of times ops need to be exectued
  for (int i = 1; i <= m; i++) diff[i] += diff[i - 1];

  vll diff2(n + 2, 0);

  int i = 1;
  for (auto [l, r, d] : ops) {
    ll val = d * diff[i];

    diff2[l] += val;
    diff2[r + 1] -= val;

    i++;
  }

  for (int i = 1; i <= n; i++) {
    diff2[i] += diff2[i - 1];
    a[i] += diff2[i];
  }

  for (int i = 1; i <= n; i++) cout << a[i] << " ";
  cout << endl;
}

int main() {
  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}