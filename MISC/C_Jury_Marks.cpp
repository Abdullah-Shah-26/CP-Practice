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
  ll n, k;
  cin >> n >> k;

  ll a[n];
  ll sum = 0;

  for (int i = 0; i < n; i++) {
    ll x;
    cin >> x;

    sum += x;
    a[i] = sum;
  }

  map<ll, ll> mp;

  for (int i = 0; i < n; i++) mp[a[i]] = 1;

  ll b[k];
  for (int i = 0; i < k; i++) cin >> b[i];

  set<ll> st;

  // x + a[i] == b[j]
  // x = b[j] - a[i]
  for (int i = 0; i < n; i++) st.insert(b[0] - a[i]);

  int cnt = 0;
  for (auto& x : st) {
    int f = 0;

    for (int i = 0; i < k; i++) {
      if (mp[b[i] - x] == 0) {
        f = 1;
        break;
      }
    }

    if (f == 0) cnt++;
  }

  cout << cnt << endl;
}

int main() {
  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}