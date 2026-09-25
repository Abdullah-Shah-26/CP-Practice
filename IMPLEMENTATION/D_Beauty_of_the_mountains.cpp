#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Solution {
public:
  void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<ll>> a(n, vector<ll>(m));

    ll D = 0;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> a[i][j];
      }
    }

    vector<string> s(n);

    for (int i = 0; i < n; i++)
      cin >> s[i];

    // pref = number of 0s in the rectangle
    // from (0,0) to (i-1,j-1)
    vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0));

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {

        if (s[i][j] == '0')
          D += a[i][j];
        else
          D -= a[i][j];

        pref[i + 1][j + 1] =
            pref[i][j + 1] +
            pref[i + 1][j] -
            pref[i][j] +
            (s[i][j] == '0');
      }
    }

    int g = 0;

    // Try every k x k square.
    for (int i = 0; i + k <= n; i++) {
      for (int j = 0; j + k <= m; j++) {

        // Number of zeros inside this k x k square.
        int z = pref[i + k][j + k]
              - pref[i][j + k]
              - pref[i + k][j]
              + pref[i][j];

        // This square changes D by:
        // c * (2*z - k*k)
        int change = abs(2 * z - k * k);

        g = gcd(g, change);
      }
    }

    if (g == 0) {
      cout << (D == 0 ? "YES\n" : "NO\n");
    }
    else {
      cout << (D % g == 0 ? "YES\n" : "NO\n");
    }
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  Solution sol;

  while (t--)
    sol.solve();

  return 0;
}