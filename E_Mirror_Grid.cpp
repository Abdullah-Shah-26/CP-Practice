#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;  // Read the number of test cases

  while (t--) {
    int n;
    cin >> n;  // Read the size of the grid for each test case

    // Initialize the grid with n x n dimensions
    vector<vector<char>> mat(n, vector<char>(n));

    // Read the grid values
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) cin >> mat[i][j];
    }  // O(n^2) to read the grid

    int ans = 0;  // Initialize the answer for the minimum number of operations

    // Iterate over each cell in the grid
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        int c0 = 0, c1 = 0;  // Counters for 0s and 1s

        // Check the current cell and its three symmetric counterparts
        if (mat[i][j] == '0')
          c0++;
        else
          c1++;

        if (mat[j][n - i - 1] == '0')
          c0++;
        else
          c1++;

        if (mat[n - i - 1][n - j - 1] == '0')
          c0++;
        else
          c1++;

        if (mat[n - j - 1][i] == '0')
          c0++;
        else
          c1++;

        // If all are 0s or all are 1s, no operation is needed
        if ((c0 == 0) or (c1 == 0)) continue;

        // If 1s are in minority, change all 1s to 0s
        if (c0 >= c1) {
          ans += c1;
          mat[i][j] = '0';
          mat[j][n - i - 1] = '0';
          mat[n - i - 1][n - j - 1] = '0';
          mat[n - j - 1][i] = '0';
        } else {
          // If 0s are in minority, change all 0s to 1s
          ans += c0;
          mat[i][j] = '1';
          mat[j][n - i - 1] = '1';
          mat[n - i - 1][n - j - 1] = '1';
          mat[n - j - 1][i] = '1';
        }
      }
    }

    // Output the minimum number of operations for the current test case
    cout << ans << "\n";
  }

  return 0;
}

// Time Complexity (TC): O(t * n^2)
// Space Complexity (SC): O(t * n^2)
