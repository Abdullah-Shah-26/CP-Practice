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
  int n;
  cin >> n;

  vi a(n), lastPos(n, -1), isLast(n, 0);

  for (int& x : a) {
    cin >> x;
    x--;
  }

  for (int i = n - 1; i >= 0; i--) {
    if (lastPos[a[i]] == -1) {
      lastPos[a[i]] = i;
      isLast[i] = 1;
    }
  }

  vi ans;
  multiset<int> st;

  int l = 0, r = -1;
  bool pickMax = 1;

  while (r + 1 < n) {
    while (r + 1 < n && (r == -1 || !isLast[r])) {
      r++;

      if (isLast[lastPos[a[r]]]) st.insert(a[r]);
    }

    if (st.empty()) continue;

    int x = pickMax ? *st.rbegin() : *st.begin();
    pickMax ^= 1;
    ans.pb(x);

    isLast[lastPos[x]] = 0;

    while (a[l] != x) {
      auto it = st.find(a[l]);

      if (it != st.end()) st.erase(it);

      l++;
    }

    st.erase(x);
    l++;
  }

  cout << ans.size() << endl;
  for (int x : ans) cout << x + 1 << " ";
  cout << endl;
}

int main() {
  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}