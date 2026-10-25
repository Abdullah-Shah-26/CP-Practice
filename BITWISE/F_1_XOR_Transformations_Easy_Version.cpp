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

int n, q;
const int N = 60;

vi t(vi& a) {
  vi b;
  b.reserve(1LL * n * (n - 1) / 2);

  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++) b.pb(a[i] ^ a[j]);

  sort(all(b));
  b.resize(n);

  return b;
}

void solve() {
  cin >> n >> q;

  vi a(n);
  rv(a);

  sort(all(a));

  vi ans(N + 1);

  for (int s = 0; s <= N; s++) {
    ans[s] = (a.back() - a.front());

    if (s == N) break;

    if (a.front() == 0 && a.back() == 0) {
      for (int i = s + 1; i <= N; i++) ans[i] = 0;
      break;
    }

    a = t(a);
  }

  while (q--) {
    int x;
    cin >> x;

    if (x >= N)
      cout << 0 << endl;
    else
      cout << ans[x] << endl;
  }
}

int main() {
  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}