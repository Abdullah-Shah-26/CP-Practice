#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 998244353;
const int N = 200005;

int n;
vector<int> a;
ll pairs[N][2][2], dp[N][2][2];

ll solve(int i, int p1, int p2) {
  if (i <= 1) return 0;

  ll& ans = dp[i][p1][p2];
  if (ans != -1) return ans;

  ans = solve(i - 1, p1, p2);

  int p = a[i] % 2;
  if (p == p2) {
    int need = p1 ^ p2;

    ans = (ans + solve(i - 1, need, p1)) % MOD;
    ans = (ans + pairs[i - 1][need][p1]) % MOD;
  }

  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  a.resize(n);

  ll cnt[2] = {};

  for (int i = 0; i < n; i++) {
    cin >> a[i];
    int p = a[i] % 2;

    if (i > 0) {
      for (int x = 0; x < 2; x++) {
        for (int y = 0; y < 2; y++) {
          pairs[i][x][y] = pairs[i - 1][x][y];
        }
      }

      for (int x = 0; x < 2; x++) {
        pairs[i][x][p] = (pairs[i][x][p] + cnt[x]) % MOD;
      }
    }

    cnt[p]++;
  }

  memset(dp, -1, sizeof(dp));

  ll ans = 0;
  for (int p1 = 0; p1 < 2; p1++) {
    for (int p2 = 0; p2 < 2; p2++) {
      ans = (ans + solve(n - 1, p1, p2)) % MOD;
    }
  }

  cout << ans << '\n';
}