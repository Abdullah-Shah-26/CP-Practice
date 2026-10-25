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
  string s;
  cin >> s;

  int n = (int)s.size();

  // Need
  int opens = n / 2;
  for (int i = 0; i < n; i++)
    if (s[i] == '(') opens--;

  // Need pos of ? where we put last '('
  // Need pos of ? where we put first ')'
  int lastOpen = -1, firstClose = -1;

  for (int i = 0; i < n; i++) {
    if (s[i] == '?' && opens > 0) {
      lastOpen = i;
      s[i] = '(';
      opens--;
    } else if (s[i] == '?') {
      if (firstClose == -1) firstClose = i;

      s[i] = ')';
    }
  }

  if (lastOpen == -1 || firstClose == -1) {
    YES;
    return;
  }

  // All ?  were forced to 1 type only, which implies reconstruction is unique 
  if(lastOpen == -1 || firstClose == -1){
    YES;
    return;
  }

  swap(s[lastOpen], s[firstClose]);

  // If its still balanced then we have multiple RBS 
  int balance = 0; 
  for(int i = 0; i < n; i++){
    balance += (s[i] == '(') ? 1 : -1;

    if(balance < 0){
      YES;
      return;
    }
  }

  NO;
}

int main() {
  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}