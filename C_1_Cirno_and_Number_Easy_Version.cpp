#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// Ordered Set
#define oset                                   \
  tree<int, null_type, less<int>, rb_tree_tag, \
       tree_order_statistics_node_update>
// order_of_key(k) : No of Elements < k
// *find_by_order(i) : Value at idx i (0 - based)

// ---------- Type aliases ----------
using ll = long long;
using ull = unsigned long long;
using ld = long double;
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

// ---------- Constants ----------
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;

// ---------- Fast IO ----------
static const auto fastio = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}();

// ---------- Macros ----------
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
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define pb push_back
#define eb emplace_back
#define rs resize
#define as assign
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define yno(a) cout << ((a) ? "YES\n" : "NO\n")
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define per(i, a, b) for (int i = (b) - 1; i >= (a); --i)
#define nl        \
  do {            \
    cout << '\n'; \
  } while (0)

ll a;
string s;
int L;
ll ans;

void check(ll val) {
  if (val < 0) return;
  ll diff = abs(a - val);
  if (ans == -1 || diff < ans) ans = diff;
}

// ---------- Solve ---------
void solve() {
  int n;
  cin >> a >> n;
  int d0, d1;
  cin >> d0 >> d1;

  s = to_string(a);
  L = s.length();
  ans = -1;

  if (L > 1) check(stoll(string(L - 1, '0' + d1)));
  check(stoll(to_string(d0 ? d0 : d1) + string(L, '0' + d0)));
  if (d0 == 0) check(0);

  string pref = "";
  int D[2] = {d0, d1};

  for (int i = 0; i < L; i++) {
    for (int d : D) {
      if (i == 0 && L > 1 && d == 0) continue;
      for (int fill : D) {
        check(stoll(pref + to_string(d) + string(L - i - 1, '0' + fill)));
      }
    }

    int cur = s[i] - '0';
    if (cur == d0 || cur == d1) {
      pref += s[i];
    } else {
      return;
    }
  }
  check(stoll(pref));

}

// ---------- Main ----------
int main() {
  int t;
  cin >> t;
  while (t--){ solve();
  cout << ans << endl;
  }
  return 0;
}