#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  string A, B;
  cin >> A >> B;

  // dp[i][j]: best similarity score using prefixes A[0..i-1], B[0..j-1].
  // Starting a new pair of substrings is implicit because all states are
  // initialized to 0 and we always take max when transitioning (local-alignment
  // style DP).
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

  int ans = 0;  // maximal score over all pairs of substrings
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= m; ++j) {
      // Extend only A's substring: pay -1 for increasing |C| by 1
      if (i < n) dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] - 1);

      // Extend only B's substring: pay -1 for increasing |D| by 1
      if (j < m) dp[i][j + 1] = max(dp[i][j + 1], dp[i][j] - 1);

      // Match A[i] with B[j]: contributes +2 (LCS +1 gives +4, lengths +1+1
      // give -2)
      if (i < n && j < m && A[i] == B[j])
        dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + 2);

      // Track the best value seen so far over all endpoints (all substring
      // pairs)
      ans = max(ans, dp[i][j]);
    }
  }

  cout << ans << '\n';
  return 0;
}

// Time Complexity per test case: O(n * m)
// Space Complexity per test case: O(n * m)
