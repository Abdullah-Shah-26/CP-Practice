#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;

void solve() {
  int n;
  cin >> n;

  vll a(n);
  for (auto& x : a) cin >> x;

  vll b = a;
  sort(b.begin(), b.end());

  int l = 0, r = n - 1;

  while (l < n && a[l] == b[l]) {
    l++;
  }

  while (r >= 0 && a[r] == b[r]) {
    r--;
  }

  if (l >= r) {
    cout << "yes\n";
    cout << "1 1\n";
    return;
  }

  reverse(a.begin() + l, a.begin() + r + 1);

  if (a == b) {
    cout << "yes\n";
    cout << l + 1 << " " << r + 1 << '\n';
  } else {
    cout << "no\n";
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
  return 0;
}