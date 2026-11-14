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



==========================
*/

void solve() {
  int n, k;
  cin >> n >> k;

  map<int, int> freq;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    freq[x]++;
  }

  vi cnt;

  for (auto [x, f] : freq) cnt.pb(f);

  sort(rall(cnt));

  auto check = [&](int mid) {
    int sum = 0;

    for (int f : cnt) {
      sum += f / mid;

      if (sum >= k) return 1;
    }

    return 0;
  };

  int low = 1, high = n / k;
  int ans = 1;

  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (check(mid)) {
      ans = mid;
      low = mid + 1;
    } else
      high = mid - 1;
  }

  vi res;

  for (auto [x, f] : freq) {
    int take = f / ans;

    while (take-- && res.size() < k) res.pb(x);

    if (res.size() == k) break;
  }

  for (int x : res) cout << x << " ";

  cout << "\n";
}

int main() {
  int t = 1;
  // cin >> t;

  while (t--) {
    solve();
  }
  return 0;
}