#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;

  int cnt = 0;

  for (int y = b; y <= c; y++) {
    int l, r;

    // Case 1 : Contribution = 0
    // Case 2 :
    l = max(a, c - y);
    r = min(b, d - y);

    if (l <= r)
      cnt += (r - l + 1) * (y - c) + (r * (r + 1) / 2) - (l * (l - 1) / 2);

    // Case 3 :
    l = max(a, d - y + 1);
    r = b;

    if (l <= r) 
      cnt += (r - l + 1) * (d - c + 1);
  }

  cout << cnt << endl;

  return 0;
}
