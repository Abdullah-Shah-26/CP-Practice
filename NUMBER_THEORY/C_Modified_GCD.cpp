#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
  int q, a, b, l, h;
  cin >> a >> b;

  int gcd = __gcd(a, b);

  vector<int> divisors;
  for (int i = 1; i * i <= gcd; i++) {
    if (gcd % i == 0) {
      divisors.push_back(i);

      if (i != gcd / i) {
        divisors.push_back(gcd / i);
      }
    }
  }

  cin >> q;
  while (q--) {
    cin >> l >> h;

    int res = -1;

    for (int d : divisors) {
      if (d >= l && d <= h) {
        res = max(res, d);
      }
    }

    cout << res << endl;
  }
}
