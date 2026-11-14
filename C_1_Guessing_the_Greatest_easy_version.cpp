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

/*
==========================

First i ask the whole segment [l, r - 1] about pos of second max 
Then if pos < mid 
  I ask subsegment [l, mid-1] == pos 
    r = mid
  else 
    l = mid
else
  I ask subsegment [mid, r - 1] == pos
    l = mid
  else
    r = mid 

==========================
*/

int ask(int l, int r) {
  if (l >= r) return -1;

  cout << "? " << l + 1 << " " << r + 1 << endl;

  int ans;
  cin >> ans;

  return ans - 1;  // Idx of second max element, but we want in 0 based
}

void solve() {
  int n;
  cin >> n;

  int l = 0, r = n;

  // There must be atleast 2 elements to find second max
  while (r - l > 1) {
    int mid = (l + r) >> 1;
    int smax = ask(l, r - 1);

    // segment [l, r)
    // [l, mid -1] [mid, r - 1]

    if (smax < mid) {
      if (ask(l, mid - 1) == smax)
        r = mid;
      else
        l = mid;
    } else {
      if (ask(mid, r - 1) == smax)
        l = mid;
      else
        r = mid;
    }
  }

  cout << "! " << r << endl;
}

int main() {
  int t = 1;
  while (t--) {
    solve();
  }

  return 0;
}