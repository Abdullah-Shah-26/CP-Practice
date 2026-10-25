#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  ll ciel = 0, jiro = 0;
  vector<int> mid;

  for (int i = 0; i < n; i++) {
    int s;
    cin >> s;

    vector<int> a(s);
    for (int& x : a) cin >> x;

    for (int j = 0; j < s / 2; j++) ciel += a[j];

    for (int j = (s + 1) / 2; j < s; j++) jiro += a[j];

    if (s % 2 == 1) mid.push_back(a[s / 2]);
  }

  sort(mid.rbegin(), mid.rend());

  for (int i = 0; i < (int)mid.size(); i++) {
    if (i % 2 == 0)
      ciel += mid[i];
    else
      jiro += mid[i];
  }

  cout << ciel << ' ' << jiro << '\n';

  return 0;
}