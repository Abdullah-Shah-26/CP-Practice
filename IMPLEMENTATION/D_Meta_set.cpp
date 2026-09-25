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

ABC
ADE

A = common guy

ABCDE = Meta Set



==========================
*/

ll encode(vi& a) {
  ll x = 0, p = 1;

  for (auto v : a) {
    x += v * p;
    p *= 3;
  }

  return x;
}

void solve() {
  int n, k;
  cin >> n >> k;

  vvi a(n, vi(k));
  unordered_map<ll, int> id;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < k; j++) cin >> a[i][j];
    id[encode(a[i])] = i;
  }

  vi cnt(n, 0);

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      
      // The c we need for pair (i, j)
      vi c(k);

      for (int x = 0; x < k; x++) {
        if (a[i][x] == a[j][x])
          c[x] = a[i][x];
        else
          c[x] = 3 - a[i][x] - a[j][x];
      }

      ll code = encode(c);

      if(id.count(code)){
        int x = id[code];
      
        // i < j already
        // i < j < x
        if(j < x){
          cnt[i]++;
          cnt[j]++;
          cnt[x]++;
        }
      }
    }
  }

  ll ans = 0;

  for(int i = 0; i < n; i++)
    ans += 1LL * cnt[i] * (cnt[i] - 1)/2;

  cout << ans << endl;
}

int main() {
  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}