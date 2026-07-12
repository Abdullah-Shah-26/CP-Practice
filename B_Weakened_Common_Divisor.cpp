#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<pair<ll, ll>> a(n);

  for (int i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second;
  }

  vector<ll> candidates;

  auto addPrimeFactors = [&](ll x) {
    for (ll i = 2; i * i <= x; i++) {
      if (x % i == 0) {
        candidates.push_back(i);
        while (x % i == 0) x /= i;
      }
    }
    if (x > 1) candidates.push_back(x);
  };

  addPrimeFactors(a[0].first);
  addPrimeFactors(a[0].second);

  sort(candidates.begin(), candidates.end());
  candidates.erase(unique(candidates.begin(), candidates.end()),
                   candidates.end());

  for (ll p : candidates) {
    bool ok = true;

    for (int i = 0; i < n; i++) {
      if (a[i].first % p != 0 && a[i].second % p != 0) {
        ok = false;
        break;
      }
    }

    if (ok) {
      cout << p << '\n';
      return 0;
    }
  }

  cout << -1 << '\n';

  return 0;
}