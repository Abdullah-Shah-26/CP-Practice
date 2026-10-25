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
const int MOD = 998244353;

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
  int n, k;
  cin >> n >> k;

  vi a(n), pos(n);

  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i]--;
    pos[a[i]] = i;
  }

  set<int> s;
  vi b(k);

  for (int i = 0; i < k; i++) {
    cin >> b[i];
    b[i]--;
    s.insert(b[i]);
  }

  ll ans = 1;

  for (auto val : b) {
    int p = pos[val];

    int blocked = 0, nei = 0;

    if (p > 0) {
      blocked += (s.find(a[p - 1]) != s.end());
      nei++;
    }

    if (p < n - 1) {
      blocked += (s.find(a[p + 1]) != s.end());
      nei++;
    }

    ans = (ans * (nei - blocked)) % MOD;

    s.erase(val);
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