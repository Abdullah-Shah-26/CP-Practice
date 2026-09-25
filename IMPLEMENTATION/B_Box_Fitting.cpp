#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n;
    ll W;
    cin >> n >> W;

    vector<int> cnt(31, 0);

    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;

      int p = 0;
      while ((1 << p) != x) p++;

      cnt[p]++;
    }

    int height = 0;
    int left = n;

    while (left > 0) {
      ll remaining = W;

      // For each layer      

      // Fill one row, largest -> smallest.
      for (int p = 30; p >= 0; p--) {
        ll width = 1LL << p;

        // Try to place as many large pieces as possible 
        while (cnt[p] > 0 && width <= remaining) {
          remaining -= width;
          cnt[p]--;
          left--;
        }
      }

      height++;
    }

    cout << height << '\n';
  }

  return 0;
}