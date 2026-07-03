#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<ll> a(n);
    for (auto &x : a) cin >> x;

    auto ok = [&](ll c) {
        vector<int> dp(n, 1);
        int best = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (abs(a[i] - a[j]) <= c * (i - j)) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            best = max(best, dp[i]);
        }

        return (n - best) <= k;
    };

    ll l = -1, r = 2e9 + 20;

    while(r - l > 1){
      ll mid = l + (r - l)/2;

      if(ok(mid)) r = mid;
      else l = mid;
    }


    cout << r << '\n';
}