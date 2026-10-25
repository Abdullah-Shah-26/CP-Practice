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

const int M = 1e6;

void solve() {
  int n;
  cin >> n;

  vi last(2 * M + 1, 0);
  rep(i, 0, n) {
    int x;
    cin >> x;
    last[x] = x;
  }

  // last[v] = largest val <= v
  for (int v = 1; v <= 2 * M; v++) {
    if (!last[v]) last[v] = last[v - 1];
  }

  int ans = 0; 

  for(int x = 1; x <= M; x++){
    if(last[x] != x) // x is not in arr
      continue;

    // bucket [k - x, k)
    // Its largest element is last[k - 1]
    for(int k = 2 * x; k <= M + x; k += x)
      ans = max(ans, last[k - 1] % x);
  }

  cout << ans << endl;

  return;
}

int main() {
  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}