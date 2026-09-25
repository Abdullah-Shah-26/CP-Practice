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
const ll LINF = 4e18;
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
  int n, m;
  cin >> n >> m;

  vll trees(n);
  rv(trees);

  map<ll, ll> dist;
  queue<ll> q;

  for (auto x : trees) {
    dist[x] = 0;
    q.push(x);
  }

  vll ans;
  ll total = 0;

  while (!q.empty() && ans.size() < m) {
    ll cur = q.front();
    q.pop();

    for (int d = -1; d <= 1; d += 2) {
      ll nx = cur + d;

      if (dist.find(nx) != dist.end()) continue;

      q.push(nx);
      dist[nx] = dist[cur] + 1;

      ans.push_back(nx);
      total += dist[nx];

      if ((int)ans.size() == m) break;
    }
  }

  cout << total << endl;
  for (auto x : ans) cout << x << " ";

  return;
}

int main() {
  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}