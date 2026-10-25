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
  string s;
  cin >> s;

  string s1 = "";

  for (char ch : s) s1 += tolower(ch);

  cin >> s;

  string s2 = "";

  for (char ch : s) s2 += tolower(ch);

  if (s1.size() < s2.size() || (s1.size() == s2.size() && s1 < s2)) {
    cout << -1 << endl;
    return;
  }

  if (s2.size() < s1.size() || (s2.size() == s1.size() && s2 < s1)) {
    cout << 1 << endl;
    return;
  }

  if (s1 == s2) {
    cout << 0 << endl;
    return;
  }
}

int main() {
  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}