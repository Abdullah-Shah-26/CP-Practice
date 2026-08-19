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
  int n;
  ll money;

  cin >> n >> money;

  vvll need(n), gain(n);
  vvpll ms(n);  // milestone achieved : [money req, floorNo]

  rep(i, 0, n) {
    int m;
    cin >> m;

    vll a(m + 1), b(m + 1);

    for (int j = 1; j <= m; j++) cin >> a[j];
    for (int j = 1; j <= m; j++) cin >> b[j];

    need[i].assign(m + 1, 0);
    gain[i].assign(m + 1, 0);

    for (int j = 1; j <= m; j++) {
      gain[i][j] = gain[i][j - 1] + (b[j] - a[j]);
      need[i][j] = max(need[i][j - 1], a[j] - gain[i][j - 1]);
    }

    ll bestGain = 0;

    for (int j = 1; j <= m; j++) {
      if (gain[i][j] > bestGain) {
        ll req = need[i][j] + bestGain;
        ms[i].pb({req, j});
        bestGain = gain[i][j];
      }
    }
  }

  priority_queue<pll, vpll, greater<pll>> pq;  // [req money, building idx]

  vi ptr(n, 0);  // b[0] -> [0, 1, 2, 3]
  vi reached(n, 0);

  rep(i, 0, n) {
    if (!ms[i].empty()) {
      pq.push({ms[i][0].first, i});
    }
  }

  while (!pq.empty()) {
    auto [req, b] = pq.top();
    pq.pop();

    if (req > money) break;

    int f = ms[b][ptr[b]].second;
    money += gain[b][f] - gain[b][reached[b]];
    reached[b] = f;

    ptr[b]++;

    if (ptr[b] < ms[b].size()) {
      pq.push({ms[b][ptr[b]].first, b});
    }
  }

  int bestHt = 0, bestB = 1;

  rep(i, 0, n) {
    ll have = money - gain[i][reached[i]];

    // deepest affordable floor
    int ht = upper_bound(all(need[i]), have) - begin(need[i]) - 1;

    if (ht > bestHt) {
      bestHt = ht;
      bestB = i + 1;
    }
  }

  cout << bestHt << " " << bestB << endl;
}

int main() {
  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}