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
#define pf(x) cout << x << '\n'
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

int n, k;
vi seq;

void f(int i, int remk) {
  if (i == n) {
    if (remk % n == 0) {
      seq[n - 1] = remk / n;

      for (int j = 0; j < n; j++) cout << seq[j] << " ";

      cout << endl;
    }

    return;
  }

  int maxi = remk / i;
  for (int val = 0; val <= maxi; val++) {
    seq[i - 1] = val;
    f(i + 1, remk - (val * i));
  }
}

void solve() {
  cin >> n >> k;

  seq.resize(n);
  f(1, k);
}

int main() {
  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}