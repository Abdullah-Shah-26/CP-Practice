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

void solve() {
  int n, m, x, y;
  cin >> n >> m >> x >> y;

  vll a(x), b(y);
  rv(a);
  rv(b);

  vll X,Y,Z;
  ll i = 0, j = 0; 

  while(i < x && j < y){
    if(a[i] < b[j]){
      X.pb(a[i]);
      i++;
    }
    else if(a[i] > b[j]){
      Y.pb(b[j]);
      j++;
    }
    else{
      Z.pb(a[i]);
      i++;
      j++;
    }
  }

  while(i < x){
    X.pb(a[i]);
    i++;
  }

  while(j < y){
    Y.pb(b[j]);
    j++;
  }

  vll P;
  int takeX = min((int)X.size(), n);
  rep(k, 0, takeX){
    P.pb(X[X.size() - k - 1]);
  }

  int takeY = min((int)Y.size(), m);
  rep(k, 0, takeY){
    P.pb(Y[Y.size() - k - 1]);
  }

  for(ll z : Z)
    P.pb(z);

  sort(rall(P));

  int limit = min((int)P.size(), n + m - 1);
  ll ans = 0; 

  rep(k, 0, limit){
    ans += P[k];
  }

  pf(ans);
}

int main() {
  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}