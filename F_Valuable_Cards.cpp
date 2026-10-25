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

const int N = 1e5 + 1;
bool reach[N];  // reach[p] = can product p be formed in cur segment

void solve() {
  int n, x;
  cin >> n >> x;

  // divisors of x
  vi divs;
  for (int d = 1; d * d <= x; d++) {
    if (x % d == 0) {
      divs.pb(d);

      if (d != x / d) divs.pb(x / d);
    }
  }

  sort(all(divs));

  auto reset = [&](){
    for(int d : divs)
      reach[d] = false;

    reach[1] = true; // empty subset
  };

  reset();
  int ans = 1; 

  for(int i = 0; i < n; i++){
    int a;
    cin >> a;

    // a can never be in making prodcut x if it isnt the divisor of x
    if(x % a)
      continue;

    for(int j = divs.size() - 1; j >= 0; j--){
      ll p = 1LL * divs[j] * a;

      if(p <= x && x % p == 0 && reach[divs[j]])
        reach[p] = true;
    }

    // If i can reach x, cut the segment & reset reachable's
    // This a needs to be part of another segment
    if(reach[x]){
      ans++;
      reset();
      reach[a] = true;
    }
  }

  for(int d : divs) reach[d] = false;
  
  cout << ans << endl;
}

int main() {
  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}