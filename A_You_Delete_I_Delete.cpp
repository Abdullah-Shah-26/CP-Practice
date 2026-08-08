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
const ll LINF = 1e18;
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
#define pf(x) cout << x << '\n'
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define pb push_back
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define endl '\n'

/*
==========================

Alice -> 0 from back
Bob -> 1 from front

==========================
*/

void solve() {
  string s;
  cin >> s;

  int n = s.size();

  vector<bool> d(n, true);

  // Alice - Find idx of first 0 & delete it 
  for(int i = 0; i < n; i++){
    if(s[i] == '0'){
      d[i] = false;
      break;
    }
  }

  // Bob - Find idx of first 1 & delete it 
  for (int i = 0; i < n; i++) {
    if (s[i] == '1') {
      d[i] = false;
      break;
    }
  }

  string ans = "";

  for (int i = 0; i < n; i++) {
    if (d[i]) {
      ans += s[i];
    }
  }

  pf(ans);
}

int main() {
  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
