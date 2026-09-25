#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;

  while (T--) {
    int n;
    cin >> n;

    vector<pair<int, int>> p(n);
    vector<int> topicCnt(n + 1, 0);
    vector<int> diffCnt(n + 1, 0);

    for (int i = 0; i < n; i++) {
      cin >> p[i].first >> p[i].second;
      topicCnt[p[i].first]++;
      diffCnt[p[i].second]++;
    }

    ll ans = 1LL * n * (n - 1) * (n - 2) / 6;

    for (auto [a, b] : p) {
      ans -= 1LL * (topicCnt[a] - 1) * (diffCnt[b] - 1);
    }

    cout << ans << '\n';
  }
}