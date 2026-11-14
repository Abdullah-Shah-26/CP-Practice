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

  vi a(n);
  for (int& x : a) cin >> x;

  vi suffMin(n);
  suffMin[n - 1] = a[n - 1];

  for (int i = n - 2; i >= 0; i--) suffMin[i] = min(suffMin[i + 1], a[i]);

  for (int i = 0; i < n; i++) {
    int j = lower_bound(all(suffMin), a[i]) - suffMin.begin() - 1;
    if (j > i)
      cout << j - i - 1 << " ";
    else
      cout << -1 << " ";
  }

  cout << endl;
}

int main() {
  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}