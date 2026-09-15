#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;

ll modPow(ll a, ll b) {
  ll result = 1;

  while (b > 0) {
    if (b & 1) result = result * a % MOD;

    a = a * a % MOD;
    b >>= 1;
  }

  return result;
}

void solve() {
  int n, m;
  cin >> n >> m;

  vector<ll> a(n);
  for (auto& x : a) cin >> x;

  // Sort all levels.
  sort(a.begin(), a.end());

  // Compress the array:
  // values = distinct levels
  // freq[i] = number of students having values[i]
  vector<ll> values;
  vector<ll> freq;

  for (int i = 0; i < n;) {
    int j = i;

    while (j < n && a[j] == a[i]) j++;

    values.push_back(a[i]);
    freq.push_back(j - i);

    i = j;
  }

  int k = values.size();

  if (k < m) {
    cout << 0 << '\n';
    return;
  }

  // inv[x] = modular inverse of x.
  vector<ll> inv(n + 1);

  for (int x = 1; x <= n; x++) inv[x] = modPow(x, MOD - 2);

  ll product = 1;
  ll answer = 0;

  int left = 0;

  for (int right = 0; right < k; right++) {
    // Add the new level to the window.
    product = product * freq[right] % MOD;

    // If the range is too large, remove levels from the left.
    while (values[right] - values[left] >= m) {
      product = product * inv[freq[left]] % MOD;
      left++;
    }

    // Number of distinct levels currently in the window.
    int windowSize = right - left + 1;

    // We need exactly m distinct levels.
    if (windowSize == m) {
      answer = (answer + product) % MOD;

      // Remove the leftmost level before moving forward.
      product = product * inv[freq[left]] % MOD;
      left++;
    }
  }

  cout << answer << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) solve();

  return 0;
}