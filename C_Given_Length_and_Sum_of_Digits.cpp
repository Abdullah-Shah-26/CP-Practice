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
  int m, sum;
  cin >> m >> sum;

  if (m * 9 < sum || (sum == 0 && m > 1)) {
    cout << -1 << " " << -1 << endl;
    return;
  }

  vi maxi(m, 0);
  int temp = sum;

  for (int i = 0; i < m; i++) {
    int d = min(9, sum);
    maxi[i] = d;
    sum -= d;
  }

  vi mini(m, 0);
  mini[0] = 1;
  temp--;

  for (int i = m - 1; i >= 0; i--) {
    int add = min(9 - mini[i], temp);
    temp -= add;
    mini[i] += add;
  }

  for (int i = 0; i < m; i++) cout << mini[i];
  cout << " ";
  for (int i = 0; i < m; i++) cout << maxi[i];

  cout << endl;
}

int main() {
  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}