#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

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

using ordered_set = tree<pll, null_type, less<pll>, rb_tree_tag,
                         tree_order_statistics_node_update>;

void solve() {
  int n;
  ll L, R;
  cin >> n >> L >> R;

  vll p(n + 1);
  for (int i = 1; i <= n; i++) {
    ll x;
    cin >> x;
    p[i] = p[i - 1] + x;
  }

  ordered_set st;
  ll ans = 0;

  st.insert({p[0], 0});

  for (int r = 1; r <= n; r++) {
    ll low = st.order_of_key({p[r] - R, -1}); 
    ll high = st.order_of_key({p[r] - L + 1, -1});

    ans += high - low;
    st.insert({p[r], r});
  }

  cout << ans << endl;
}

int main() {
  int t = 1;
  // cin >> t;

  while (t--) {
    solve();
  }
  return 0;
}