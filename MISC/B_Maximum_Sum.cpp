#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {

        int n, k;
        cin >> n >> k; 

        vector<ll> a(n);

        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        sort(a.begin(), a.end());

        // prefix sums
        vector<ll> pref(n + 1, 0);

        for(int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + a[i];
        }

        ll ans = 0;

        // x = number of times we remove 2 minimums
        for(int x = 0; x <= k; x++) {

            int left = 2 * x;

            // remaining right index
            int right = n - (k - x) - 1;

            ll sum = pref[right + 1] - pref[left];

            ans = max(ans, sum);
        }

        cout << ans << '\n';
    }
}