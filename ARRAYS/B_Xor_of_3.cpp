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
  int n;
  cin >> n;

  vi a(n);
  rv(a);

  int xorr = 0;
  for (int x : a) xorr ^= x;

  if (xorr != 0) {
    NO;
    return;
  }

  int split = -1;  // split pt

  // For odd len, whole arr = valid seg
  if (n % 2 != 0) {
    split = n - 1;
  } else {
    int prefXor = 0;

    for (int i = 0; i < n; i++) {
      prefXor ^= a[i];

      // For even len, split seg into 2 odd len seg of xor = 0
      if (i % 2 == 0 && prefXor == 0) {
        split = i;
        break;
      }
    }
  }

  if (split == -1) {
    NO;
    return;
  }

  YES;
  vi ans;

  // Sweeping 1st seg
  for (int i = 0; i + 2 <= split; i += 2) ans.pb(i + 1);
  for (int i = split - 4; i >= 0; i -= 2) ans.pb(i + 1);

  // Sweep 2nd seg
  for (int i = split + 1; i + 2 <= n - 1; i += 2) ans.pb(i + 1);
  for (int i = n - 5; i >= split + 1; i -= 2) ans.pb(i + 1);

  cout << ans.size() << endl;
  for (int x : ans) cout << x << " ";

  cout << endl;
  return;
}

int main() {
  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}