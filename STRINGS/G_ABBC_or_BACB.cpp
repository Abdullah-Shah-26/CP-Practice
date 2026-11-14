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

  int n = s.size();
  int cnt = 0;

  bool all = (s[0] == 'B' || s[n - 1] == 'B');

  for (int i = 0; i < n - 1; i++)
    if (s[i] == s[i + 1] && s[i] == 'B') all = true;

  vi lens;

  int cur = 0;

  for (int i = 0; i < n; i++) {
    if (s[i] == 'A')
      cur++;
    else {
      if (cur > 0) lens.pb(cur);
      cur = 0;
    }
  }

  if (cur > 0) lens.pb(cur);

  sort(all(lens));

  if (lens.empty()) {
    cout << 0 << endl;
    return;
  }

  int total = 0;

  if (all) total += lens[0];

  for (int i = 1; i < lens.size(); i++) total += lens[i];

  cout << total << endl;
}

int main() {
  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}