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

const int N = 200000;

void solve() {
  int n, k, q;
  cin >> n >> k >> q;

  vector<int> diff(N + 2, 0);
  vector<int> pref(N + 2, 0);

  for (int i = 0; i < n; i++) {
    int l, r;
    cin >> l >> r;

    diff[l]++;
    diff[r + 1]--;
  }

  // How many recipies cover each temperature
  for (int i = 1; i <= N; i++) diff[i] += diff[i - 1];

  // Mark admisssible temperatures (temp recommended by atleast k recipies) with 1
  for (int i = 1; i <= N; i++) {
    if (diff[i] >= k)
      pref[i] = 1;
    else
      pref[i] = 0;
  }

  for (int i = 1; i <= N; i++) pref[i] += pref[i - 1];

  while (q--) {
    int a, b;
    cin >> a >> b;
    cout << pref[b] - pref[a - 1] << '\n';
  }
}

int main() {
  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}