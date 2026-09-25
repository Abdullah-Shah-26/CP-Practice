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
#define rm(mat)         \
  for (auto& r : (mat)) \
    for (auto& x : (r)) cin >> x
#define pm(mat)                                   \
  do {                                            \
    for (const auto& r : (mat)) {                 \
      for (const auto& x : (r)) cout << x << ' '; \
      cout << '\n';                               \
    }                                             \
  } while (0)
#define pf(x) cout << x << '\n'
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define pb push_back
#define YES cout << "Yes\n"
#define NO cout << "No\n"
#define yno(a) cout << ((a) ? "Yes\n" : "No\n")
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define endl '\n'

/*
==========================



==========================
*/

bool isZero(string& s) {
  for (char& ch : s) {
    if (ch != '0') return false;
  }
  return true;
}

void solve() {
  ll n, k;
  cin >> n >> k;

  vector<string> a(n);

  for (auto& s : a) cin >> s;

  sort(all(a), [](string& x, string& y) { 
    if(x.size() != y.size())
      return x.size() > y.size();

    return x > y;
   });

  vs chosen;

  for (int i = 0; i < k; i++) {
    chosen.pb(a[i]);
  }

  bool allZeros = true;

  for (string s : chosen) {
    if (!isZero(s)) {
      allZeros = false;
      break;
    }
  }

  if (allZeros) {
    for (int i = k; i < n; i++) {
      if (!isZero(a[i])) {
        chosen[k - 1] = a[i];
        break;
      }
    }
  }

  sort(all(chosen), [](string& x, string& y) { return x + y > y + x; });

  string ans = "";

  for (string s : chosen) ans += s;

  int p = 0; 

  while(p + 1 < ans.size() && ans[p] == '0')
    p++;

  cout << ans.substr(p) << endl;
}

int main() {
  int t = 1;
  // cin >> t;

  while (t--) {
    solve();
  }
  return 0;
}