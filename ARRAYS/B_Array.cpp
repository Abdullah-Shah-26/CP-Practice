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

  vi a(n);
  rv(a);

  bool flag = false;
  map<int, int> freq;
  int L = -1, R = -1;

  int l = 0;
  int dist = 0;
  int minLen = n + 1;

  for (int r = 0; r < n; r++) {
    freq[a[r]]++;

    if (freq[a[r]] == 1) dist++;

    while (dist == k) {
      if (r - l + 1 < minLen) {
        minLen = r - l + 1;
        L = l;
        R = r;
      }

      freq[a[l]]--;

      if (freq[a[l]] == 0) dist--;

      l++;
    }
  }

  if (L == -1) {
    cout << "-1 -1" << endl;
    return;
  }

  cout << L + 1 << " " << R + 1 << endl;

  return;
}

int main() {
  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}