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



==========================
*/

void solve() {
  int n;
  cin >> n;

  vi a(n), b(n);
  rv(a);
  rv(b);

  map<pair<int, int>, int> freq;

  int ans = 0;

  for (int i = 0; i < n; i++) {
    if (a[i] == 0) {
      if (b[i] == 0) { // 0 * d + 0 = 0
        ans++;
      }
      continue;
    }

    // d = -b[i]/a[i]
    int p = -b[i], q = a[i];
    int g = __gcd(abs(p), abs(q));
    
    // To normalize
    p /= g;
    q /= g;

    if(q < 0){
      p = -p;
      q = -q;
    }

    freq[{p,q}]++;
  }

  int maxF = 0; 

  for(auto &it : freq)
    maxF = max(maxF, it.second);

  ans += maxF;

  pf(ans);
}

int main() {
  int t = 1;
  // cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}