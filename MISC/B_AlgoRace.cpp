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

dist[c][u][v] = shortest time from u -> v while using only car c

best[u][v] = min(dist[c][u][v]) over all cars c

dp[k][u][v] = min time to go from u -> v using at most k car changes

==========================
*/

void solve() {
  int n, m, r;
  cin >> n >> m >> r;

  vector<vector<vector<ll>>> a(m, vvll(n, vll(n)));

  for (int car = 0; car < m; car++) {
    for (int u = 0; u < n; u++) {
      for (int v = 0; v < n; v++) {
        cin >> a[car][u][v];
      }
    }
  }

  // Shortest path from u -> v with that car
  for (int car = 0; car < m; car++) {
    for (int mid = 0; mid < n; mid++) {
      for (int u = 0; u < n; u++) {
        for (int v = 0; v < n; v++) {
          a[car][u][v] = min(a[car][u][v], a[car][u][mid] + a[car][mid][v]);
        }
      }
    }
  }

  vvll best(n, vll(n));

  for (int u = 0; u < n; u++) {
    for (int v = 0; v < n; v++) {
      best[u][v] = a[0][u][v];
    }
  }

  // Fastest way from u -> v, I can choose which any one car i want
  for (int car = 1; car < m; car++) {
    for (int u = 0; u < n; u++) {
      for (int v = 0; v < n; v++) {
        best[u][v] = min(best[u][v], a[car][u][v]);
      }
    }
  }

  vector<vvll> dp(n);

  dp[0] = best;

  for (int k = 1; k < n; k++) {
    dp[k].assign(n, vll(n, LINF));

    for (int u = 0; u < n; u++) {
      for (int x = 0; x < n; x++) {
        for (int v = 0; v < n; v++) {
          dp[k][u][v] = min(dp[k][u][v], dp[k - 1][u][x] + best[x][v]);
        }
      }
    }
  }

  while (r--) {
    int s, t, k;
    cin >> s >> t >> k;

    k = min(k, n - 1);
    s--;
    t--;

    cout << dp[k][s][t] << endl;
  }
}

int main() {
  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}