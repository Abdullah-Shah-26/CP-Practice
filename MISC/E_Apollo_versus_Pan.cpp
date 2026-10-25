#include <bits/stdc++.h>
#define int long long
const int mod = 1e9 + 7;
using vi = std::vector<int>;
using namespace std;

void solve() {
  int n;
  cin >> n;
  vi v(n);
  vi cnt(60, 0);  // cnt[b] = how many numbers have bit b set (kept mod mod)

  for (int i = 0; i < n; i++) {
    cin >> v[i];
    for (int j = 0; j < 60; j++) {
      // Count set bits across all numbers for each bit position
      if (v[i] & (1LL << j)) {
        cnt[j]++;
        cnt[j] %= mod;
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    int sum1 = 0;  // sum over j of (v[i] & v[j])
    int sum2 = 0;  // sum over k of (v[i] | v[k])
    for (int j = 0; j < 60; j++) {
      if (v[i] & (1LL << j)) {
        // For (v[i] & v[j]): bit j contributes only when v[j] has bit j set
        sum1 += ((1LL << j) % mod) * cnt[j];
        // For (v[i] | v[k]): if v[i] has bit j set, it's set for all k
        // (contributes n times)
        sum2 += ((1LL << j) % mod) * n;
        sum1 %= mod;
        sum2 %= mod;
      } else {
        // For (v[i] | v[k]): if v[i] lacks bit j, only those k with bit j set
        // contribute
        sum2 += ((1LL << j) % mod) * cnt[j];
        sum2 %= mod;
      }
    }
    // Contribution of fixed i to the triple sum: sum_j (v[i] & v[j]) * sum_k
    // (v[i] | v[k])
    ans += (sum1 * sum2) % mod;
    ans %= mod;
  }
  cout << ans % mod << '\n';
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}

// Time Complexity per test case: O(n * 60)
// Space Complexity per test case: O(n + 60)
