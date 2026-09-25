#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> a(n);

  for (int &x : a) {
    cin >> x;
  }

  // Compress equal adjacent colors.
  vector<int> b;

  for (int x : a) {
    if (b.empty() || b.back() != x) {
      b.push_back(x);
    }
  }

  int m = b.size();

  if (m == 1) {
    cout << 0 << '\n';
    return 0;
  }

  vector<vector<int>> dp(m, vector<int>(m));

  // dp[l][r] = minimum moves to merge [l..r]
  for (int len = 2; len <= m; len++) {
    for (int l = 0; l + len - 1 < m; l++) {
      int r = l + len - 1;

      dp[l][r] = min(
        dp[l + 1][r],
        dp[l][r - 1]
      ) + 1;

      if (b[l] == b[r]) {
        dp[l][r] = min(
          dp[l][r],
          dp[l + 1][r - 1] + 1
        );
      }
    }
  }

  cout << dp[0][m - 1] << '\n';
}