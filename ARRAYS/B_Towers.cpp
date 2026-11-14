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
  int n, k;
  cin >> n >> k;

  multiset<pii> st;

  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;

    st.insert({x, i});
  }

  vpii ops;

  while (k--) {
    auto mn = st.begin();
    auto mx = prev(st.end());

    int minH = mn->first;
    int minIdx = mn->second;

    int maxH = mx->first;
    int maxIdx = mx->second;

    if (maxH - minH <= 1) break;

    st.erase(mn);
    st.erase(mx);

    st.insert({maxH - 1, maxIdx});
    st.insert({minH + 1, minIdx});

    ops.push_back({maxIdx, minIdx});
  }

  int instability = st.rbegin()->first - st.begin()->first;

  cout << instability << " " << ops.size() << endl;
  for (auto [x, y] : ops) cout << x << " " << y << endl;
}

int main() {
  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}