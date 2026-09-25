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

bool isPrime(int x) {
  if (x < 2) return false;

  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) return false;
  }

  return true;
}

vi div(int x) {
  vi d;

  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      if (isPrime(i)) {
        d.pb(i);
      }

      if (i != x / i) {
        if (isPrime(x / i)) {
          d.pb(x / i);
        }
      }
    }
  }

  return d;
}

void solve() {
  int n;
  cin >> n;

  vi a(n);

  for (int i = 0; i < n; i++) a[i] = i + 2;

  map<int, int> mp;

  // Coloring 1 to all initially
  for (int i = 0; i < n; i++) {
    mp[a[i]] = 1;
  }

  for (auto &[x, color] : mp) {
    vi primeDivisors = div(x);

    for (auto d : primeDivisors) {
      if (mp.count(d)) {
        mp[x] = mp[d] + 1;
      }
    }
  }

  set<int> st;

  for (auto [x, c] : mp) {
    st.insert(c);
  }

  cout << (int)st.size() << endl;

  for (auto [x, c] : mp) {
    cout << c << " ";
  }

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