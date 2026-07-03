#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
		ios::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		int t;
		cin >> t;
		while (t--) {
				int n, a, b;
				cin >> n >> a >> b;
				vector<int> x(n + 1);              // x[1..n] are kingdom positions; x[0] stays 0 (initial capital)
				for (int i = 1; i <= n; i++)
						cin >> x[i];

				vector<int> suf(n + 2, 0);         // suf[i] = x[i] + x[i+1] + ... + x[n]
				suf[n] = x[n];
				for (int i = n - 1; i >= 1; i--) {
						suf[i] = suf[i + 1] + x[i];    // build suffix sums to query sum of tail efficiently
				}

				int ans = INT64_MAX;               // minimal total cost over all strategies
				for (int i = 0; i <= n; i++) {
						// Consider pivot i: conquer kingdoms up to x[i] while capital is at 0, then place capital at x[i],
						// and conquer the rest from x[i]. For i = 0, we effectively never move the capital from 0.
						int c = x[i] * (a + b) + (suf[i + 1] - (n - i) * x[i]) * b;
						// x[i] * (a + b): b*x[i] (cost accrued up to x[i]) + a*x[i] (move capital to x[i])
						// (suf[i+1] - (n - i) * x[i]) * b: sum over j > i of b * (x[j] - x[i])
						ans = min(ans, c);
				}

				cout << ans << '\n';
		}

		return 0;
}

/*
Time Complexity (TC): O(n)
Space Complexity (SC): O(n)
*/
