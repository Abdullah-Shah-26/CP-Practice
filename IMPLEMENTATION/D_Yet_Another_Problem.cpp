#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;
  cin >> n >> q;

  vector<int> a(n + 1), px(n + 1, 0),
      nz(n + 1, 0);  // a: 1-indexed array, px: prefix XORs, nz: prefix count of non-zeros

  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    px[i] = px[i - 1] ^ a[i];         // XOR of a[1..i]
    nz[i] = nz[i - 1] + (a[i] != 0);  // count non-zeros in a[1..i]
  }

  unordered_map<int, vector<int>> even,
      odd;  // maps prefix XOR value -> sorted list of indices with even/odd
            // parity

  for (int i = 0; i <= n; i++) {
    if (i % 2 == 0)
      even[px[i]].push_back(
          i);  // store even-indexed positions for this prefix XOR
    else
      odd[px[i]].push_back(
          i);  // store odd-indexed positions for this prefix XOR
  }

  while (q--) {
    int l, r;
    cin >> l >> r;

    // If XOR over [l, r] is non-zero, it's impossible (operation preserves
    // subarray XOR).
    if ((px[r] ^ px[l - 1]) != 0) {
      cout << -1 << '\n';
      continue;
    }

    // Already all zeros: no operation needed.
    if (nz[r] - nz[l - 1] == 0) {
      cout << 0 << '\n';
      continue;
    }

    int len = r - l + 1;

    // Odd length and zero XOR -> one operation (apply to whole subarray).
    if (len % 2 == 1) {
      cout << 1 << '\n';
      continue;
    }

    // If either end is zero, we can ignore it, leaving an odd-length, zero-XOR
    // segment -> one op.
    if (a[l] == 0 || a[r] == 0) {
      cout << 1 << '\n';
      continue;
    }

    // Need an index k in [l, r - 1] with px[k] == px[l-1] and same parity as l.
    // Then [l, k] has odd length and XOR zero; do it first, then finish the
    // rest -> two ops.
    auto& vec = (l % 2 == 0 ? even[px[l - 1]] : odd[px[l - 1]]);
    auto it =
        lower_bound(vec.begin(), vec.end(), l);  // first candidate index >= l

    if (it != vec.end() && *it <= r - 1)
      cout << 2 << '\n';
    else
      cout << -1 << '\n';
  }

  return 0;
}

/*
Time Complexity per test case:
- Preprocessing: O(n)
- Each query: O(log n) (binary search in a parity-bucket vector)
Overall: O(n + q log n)
Space Complexity per test case: O(n) for prefix arrays and buckets
*/
