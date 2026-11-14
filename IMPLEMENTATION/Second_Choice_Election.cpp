#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;  // candidates
  int m;  // votes

  cin >> n >> m;

  vector<int> freq(n + 1);
  set<pair<int, int>> ranking;  // [votes, candidate]
  vector<vector<int>> instead(n + 1);

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    freq[a]++;
    instead[a].push_back(b);
  }

  for (int i = 1; i <= n; i++) ranking.insert({freq[i], -i});

  // If tie, candidate with smaller no wins

  for (int a = 1; a <= n; a++) {
    for (int b : instead[a]) {
      ranking.erase({freq[a], -a});
      ranking.erase({freq[b], -b});
      freq[a]--;
      freq[b]++;
      ranking.insert({freq[a], -a});
      ranking.insert({freq[b], -b});
    }

    cout << -ranking.rbegin()->second << endl;

    for (int b : instead[a]) {
      ranking.erase({freq[a], -a});
      ranking.erase({freq[b], -b});
      freq[a]++;
      freq[b]--;
      ranking.insert({freq[a], -a});
      ranking.insert({freq[b], -b});
    }
  }

  return 0;
}