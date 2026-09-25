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

bool check(int k, string& s, int n) {
  ll l = 0, r = 0;

  for (int i = 0; i < n; i++) {
    ll pl = l, pr = r;

    l = pl - k;
    r = pr + k;

    if (s[i] == '+')
      l = max(l, 1LL);
    else if (s[i] == '-')
      r = min(r, -1LL);
    else {
      l = max(l, 0LL);
      r = min(r, 0LL);
    }

    if (k == 1) {
      int req = (i + 1) % 2;

      if (abs(l) % 2 != req) l++;
      if (abs(r) % 2 != req) r--;

      if (l > r) return false;
    }

    if (l > r) return false;

    if (pl == pr) {
      ll x = pl;

      if (l == x && r == x) return false;
      if (l == x) l = x + 1;
      if (r == x) r = x - 1;
    }

    if (l > r) return false;
  }

  return true;
}

void solve() {
  int n;
  cin >> n;

  string s;
  cin >> s;

  if (!check(n, s, n)) {
    cout << -1 << endl;
    return;
  }

  int l = 1, h = n;
  int ans = n;

  while (l <= h) {
    int mid = l + (h - l) / 2;

    if (check(mid, s, n)) {
      ans = mid;
      h = mid - 1;
    } else {
      l = mid + 1;
    }
  }

  cout << ans << endl;
}

int main() {
  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}