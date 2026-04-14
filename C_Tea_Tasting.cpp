#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
		int n;
		cin >> n;
		vector<int> a(n + 1), b(n + 1); // 1-indexed arrays for simpler prefix logic
		for (int i = 1; i <= n; i++) cin >> a[i];
		for (int i = 1; i <= n; i++) cin >> b[i];

		vector<int> pr(n + 1, 0);
		for (int i = 1; i <= n; i++) pr[i] = pr[i - 1] + b[i]; // pr[i] = sum of b[1..i]

		vector<int> cnt(n + 2, 0), ans(n + 1, 0);
		for (int i = 1; i <= n; i++) {
				// x = total capacity available up to (i - 1) plus the current tea amount a[i]
				int x = a[i] + pr[i - 1];
				// j = first index where pr[j] > x, i.e., tea i finishes at taster j (partially) or before
				int j = upper_bound(pr.begin(), pr.end(), x) - pr.begin();
				// If tea i ends at taster j (j <= n), add the partial amount for taster j
				if (j <= n) {
						ans[j] += x - pr[j - 1]; // leftover for taster j after full ones
				}
				// Mark that tasters in [i, j - 1] drink their full capacities from tea i
				cnt[i]++;
				cnt[j]--;
		}
		for (int i = 1; i <= n; i++) {
				cnt[i] += cnt[i - 1]; // number of teas fully contributing to taster i
				ans[i] += cnt[i] * b[i]; // add full contributions
		}
		for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
		cout << '\n';
}

int32_t main() {
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);

		int t;
		cin >> t;
		while (t--) {
				solve();
		}
		return 0;
}

/*
Time Complexity (TC): O(nlogn)
Space Complexity (SC): O(n)
*/
