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
#define endl '\n'

// ---------- Solve ---------
void solve() {
  string s;
  cin >> s;

  vi freq(26, 0);

  for (char& ch : s) {
    freq[ch - 'a']++;
  }

  int n = s.size();

  if (*max_element(all(freq)) > (n + 1) / 2) {
    cout << "No" << endl;
    return;
  }

  priority_queue<pair<int, char>> pq;

  for (int i = 0; i < 26; i++) {
    if (freq[i]) {
      pq.push({freq[i], i + 'a'});
    }
  }

  string ans;

  while (pq.size() >= 2) {
    auto [f1, c1] = pq.top();
    pq.pop();

    auto [f2, c2] = pq.top();
    pq.pop();

    ans += c1;
    ans += c2;

    f1--;
    f2--;

    if (f1) pq.push({f1, c1});
    if (f2) pq.push({f2, c2});
  }

  if (!pq.empty()) {
    ans += pq.top().second;
  }

  cout << "Yes" << endl;
  cout << ans << endl;
}

// ---------- Main ----------
int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}