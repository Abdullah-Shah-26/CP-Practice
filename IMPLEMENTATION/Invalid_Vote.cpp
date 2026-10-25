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
  ll n, m;
  cin >> n >> m;

  vs s(n), t(m);  // candidates, ballots
  for (int i = 0; i < n; i++) cin >> s[i];
  for (int i = 0; i < m; i++) cin >> t[i];

  vll votes(n, 0);

  for (int i = 0; i < m; i++) {
    int idx = -1, cnt = 0;

    // Exact match
    for (int j = 0; j < n; j++) {
      if (t[i] == s[j]) {
        idx = j;
        break;
      }
    }

    if (idx != -1) {
      votes[idx]++;
      continue;
    }

    for (int j = 0; j < n; j++) {
      if (t[i].size() != s[j].size()) continue;

      int diff = 0;

      for (int k = 0; k < (int)t[i].size(); k++)
        if (t[i][k] != s[j][k]) diff++;

      if (diff == 1) {
        cnt++;
        idx = j;
      }
    }

    if (cnt == 1) votes[idx]++;
  }

  for (int i = 0; i < n; i++) cout << votes[i] << endl;
}

int main() {
  int t = 1;
  // cin >> t;

  while (t--) {
    solve();
  }
  return 0;
}