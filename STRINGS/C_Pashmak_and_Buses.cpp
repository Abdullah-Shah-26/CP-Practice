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
#define YES cout << "Yes\n"
#define NO cout << "No\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define endl '\n'

/*
==========================

n = no of students
k = no of buses
d = no of days

no of choices each day = k
for d days = k ^ (d)

If no of unique seq needed = n

if(total < n)
  return -1

==========================
*/

void solve() {
  ll n, k, d;
  cin >> n >> k >> d;

  ll total = 1;
  for (ll i = 0; i < d; i++) {
    total = min(1LL * n, total * k);
  }

  if (total < n) {
    cout << -1 << endl;
    return;
  }

  ll divisor = 1;
  for (ll i = 0; i < d; i++) {
    for (ll j = 0; j < n; j++) {
      cout << (j / divisor) % k + 1 << " ";
    }
    cout << endl;
    if (i + 1 < d) divisor = min(divisor * k, (ll)n);
  }
}

int main() {
  int t = 1;
  // cin >> t;

  while (t--) {
    solve();
  }
  return 0;
}