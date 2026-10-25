#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = 1e18;

int n, m, k, half;
vector<vector<ll>> horizontal, down;
vector<vector<vector<ll>>> dp;

ll rec(int i, int j, int steps) {
  if (steps == 0) return 0;

  ll &ans = dp[i][j][steps];
  if (ans != -1) return ans;

  ans = INF;

  if (i > 0)
    ans = min(ans, rec(i - 1, j, steps - 1) + down[i - 1][j]);

  if (i < n - 1)
    ans = min(ans, rec(i + 1, j, steps - 1) + down[i][j]);

  if (j > 0)
    ans = min(ans, rec(i, j - 1, steps - 1) + horizontal[i][j - 1]);

  if (j < m - 1)
    ans = min(ans, rec(i, j + 1, steps - 1) + horizontal[i][j]);

  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m >> k;

  horizontal.assign(n, vector<ll>(m - 1));
  down.assign(n - 1, vector<ll>(m));

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m - 1; j++)
      cin >> horizontal[i][j];

  for (int i = 0; i < n - 1; i++)
    for (int j = 0; j < m; j++)
      cin >> down[i][j];

  if (k % 2) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++)
        cout << -1 << ' ';
      cout << '\n';
    }
    return 0;
  }

  half = k / 2;

  dp.assign(n, vector<vector<ll>>(
    m, vector<ll>(half + 1, -1)
  ));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << 2 * rec(i, j, half) << ' ';
    }
    cout << '\n';
  }
}