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

f
o = n - f
A1 B A2 C A3 A4 A5
A4 - Trigger

A1 B A2 A3
A3 - T
usedA = 3 = o + 2

A1 B A2

==========================
*/

void solve() {
  ll n;
  cin >> n;

  unordered_map<ll, ll> freq;
  ll maxF = 0, maxV = 0, sum = 0;

  rep(i, 0, n) {
    ll x;
    cin >> x;
    sum += x;
    freq[x]++;

    if (freq[x] > maxF) {
      maxF = freq[x];
      maxV = x;
    }
  }

  ll o = n - maxF;
  ll u = min(maxF, o + 2);
  ll e = maxF - u;

  pf(sum - e * maxV);
}

int main() {
  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}