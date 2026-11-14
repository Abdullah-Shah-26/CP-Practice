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
  ll n;
  cin >> n;

  vll x(n);
  rv(x);

  sort(all(x));

  x.erase(unique(all(x)), x.end());

  vector<ll> res;

  auto can = [&](double d, vector<double> &stations) {
    int i = 0; 

    while(i < n && stations.size() < 3){
      double pos = x[i] + d;
      stations.pb(pos);

      while(i < n && x[i] <= pos + d)
        i++;
    }

    return i == n;
  };

  double low = 0, high = 1e9, ans = 0;

  for (int it = 0; it < 100; it++) {
    double mid = (low + high) / 2.0;

    vector<double> stations;

    if (can(mid, stations)) {
      ans = mid;
      high = mid;
    } else
      low = mid;
  }

  vector<double> stations;
  can(ans, stations);

  while (stations.size() < 3) stations.pb(0);

  cout << fixed << setprecision(6);
  cout << ans << endl;

  for (auto pos : stations) cout << pos << " ";
  cout << endl;

  return;
}

int main() {
  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}