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

const int M = 1000;
int maxO[M];

void pre() {
  for (int m = 1; m < M; m++)
    for (int s = 1; s <= m; s++) maxO[m] += (m / s) * s;
}

void solve() {
  int n;
  cin >> n;

  int ans = 1;
  while (maxO[ans] < n) ans++;

  cout << ans << endl;

  int bId = 1, rem = n;

  for (int s = ans; s >= 1; s--) {
    int take = min(rem / s, ans / s);

    for (int i = 0; i < take; i++) {
      for (int j = 0; j < s; j++) cout << bId << " ";
      bId++;
    }

    rem -= take * s;
  }

  cout << endl;
}

int main() {
  int t = 1;
  cin >> t;

  pre();

  while (t--) {
    solve();
  }

  return 0;
}