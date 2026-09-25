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

void solve() {
  ll n;
  cin >> n;

  vll a(n);
  map<ll, ll> freq;

  ll sum = 0;

  for (ll i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
    freq[a[i]]++;
  }

  vll ans;

  for (ll i = 0; i < n; i++) {
    // Temporarily remove a[i]
    freq[a[i]]--;

    ll rem = sum - a[i];

    if (rem % 2 == 0) {
      ll x = rem / 2;

      if (freq[x] > 0) ans.pb(i + 1);
    }

    // Restore a[i]
    freq[a[i]]++;
  }

  cout << ans.size() << endl;

  for (ll i : ans) cout << i << ' ';

  cout << endl;
}

int main() {
  solve();
  return 0;
}