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

int n;
string s;
bool used[10];
int digit[26];

bool isPrime(ll x) {
  if (x < 2) return false;

  for (ll d = 2; d * d <= x; d++) {
    if (x % d == 0) return false;
  }

  return true;
}

bool dfs(int i) {
  if (i == n) {
    ll num = 0;

    for (char c : s) num = num * 10 + digit[c - 'a'];

    if (isPrime(num)) {
      cout << num << endl;
      return true;
    }

    return false;
  }

  int c = s[i] - 'a';

  // Already assigned
  if (digit[c] != -1) return dfs(i + 1);

  for (int d = 0; d <= 9; d++) {
    if (used[d]) continue;

    if (i == 0 && d == 0) continue;

    // Do
    digit[c] = d;
    used[d] = true;

    if (dfs(i + 1)) return true;

    // Undo
    used[d] = false;
    digit[c] = -1;
  }

  return false;
}

void solve() {
  cin >> s;
  n = s.size();

  fill(digit, digit + 26, -1);

  if (!dfs(0)) {
    cout << -1 << endl;
  }

  return;
}

int main() {
  int t = 1;
  // cin >> t;

  while (t--) {
    solve();
  }
  return 0;
}