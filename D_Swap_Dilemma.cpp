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

int n;

// bool parity(vi& a) {
//   vi s = a;
//   sort(all(s));

//   int swaps = 0;

//   for (int i = 0; i < n; i++) {
//     if (a[i] == s[i]) continue;

//     for (int j = i + 1; j < a.size(); j++) {
//       if (s[i] == a[j]) {
//         swap(a[i], a[j]);
//         swaps++;
//         break;
//       }
//     }
//   }

//   return swaps % 2;
// }

int parity(vi& a) {
  vi s = a;
  sort(all(s));

  unordered_map<int, int> pos;

  for (int i = 0; i < n; i++) pos[a[i]] = i;

  int swaps = 0;

  for (int i = 0; i < n; i++) {
    if (s[i] == a[i]) continue;

    int j = pos[s[i]];  // Correct pos of a[i]

    swap(a[i], a[j]);

    pos[a[j]] = j;
    pos[a[i]] = i;

    swaps++;
  }

  return swaps % 2;
}

void solve() {
  cin >> n;

  vi a(n), b(n);
  rv(a);
  rv(b);

  unordered_set<int> st;

  for (auto x : a) st.insert(x);

  bool same = true;

  for (auto x : b) st.erase(x);

  if (st.size() != 0) same = false;

  if (same && parity(a) == parity(b))
    YES;
  else
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