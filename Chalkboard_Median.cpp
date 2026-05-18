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

// ---------- Solve ---------
void solve() {
  ll x;
  cin >> x;

  int q;
  cin >> q;

  priority_queue<ll> left;
  priority_queue<ll, vll, greater<ll>> right;

  left.push(x);

  auto balance = [&] {
    if (left.size() < right.size()) {
      left.push(right.top());
      right.pop();
    }

    if (left.size() > right.size() + 1) {
      right.push(left.top());
      left.pop();
    }
  };

  auto add = [&](ll x) {
    if (x <= left.top())
      left.push(x);
    else
      right.push(x);

    balance();
  };

  while (q--) {
    ll a, b;
    cin >> a >> b;

    add(a);
    add(b);

    cout << left.top() << endl;
  }
}

// ---------- Main ----------
int main() {
  solve();
  return 0;
}