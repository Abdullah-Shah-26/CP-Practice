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

f(a) = f(b)
f(x) = or of all no's in subseq x

==========================
*/

void solve() {
  int n;
  cin >> n;

  vvi bits(n);
  vi cnt(200001);

  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;

    for (int j = 0; j < k; j++) {
      int p;
      cin >> p;

      bits[i].pb(p);
      cnt[p]++;
    }
  }

  for (int i = 0; i < n; i++) {
    bool removeable = true;

    for (int p : bits[i]) {
      if (cnt[p] == 1) {
        removeable = false;
        break;
      }
    }

    if (removeable) {
      YES;
      return;
    }
  }

  NO;
}

int main() {
  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}