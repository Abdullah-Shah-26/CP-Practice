#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n, m;
    cin >> n >> m;

    set<vector<int>> st;
    vector<vector<int>> a(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> a[i][j];
      }

      // Build inverse permutation
      vector<int> pos(m + 1);

      for (int j = 0; j < m; j++)
        pos[a[i][j]] = j + 1;

      // Store every prefix of the inverse
      vector<int> cur;

      for (int x = 1; x <= m; x++) {
        cur.push_back(pos[x]);
        st.insert(cur);
      }
    }

    // Find the longest prefix of a[i] present in the set
    for (int i = 0; i < n; i++) {
      vector<int> cur;

      int ans = 0;

      for (int j = 0; j < m; j++) {
        cur.push_back(a[i][j]);

        if (st.count(cur))
          ans++;
        else
          break;
      }

      cout << ans << " ";
    }

    cout << '\n';
  }
}