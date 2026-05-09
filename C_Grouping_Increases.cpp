#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int ans = 0; // total penalty accumulated across both subsequences
	int x = INT_MAX, y = INT_MAX; // current last elements (tails) of the two subsequences; we maintain x <= y

	for (int i = 0; i < n; i++) {
		if (x > y) {
			swap(x, y); // keep invariant x <= y before placing a[i]
		}
		// Greedily place a[i] into the leftmost subsequence it can extend without increasing its last value.
		if (a[i] <= x) {
			x = a[i]; // extend first subsequence (non-increasing), no new increase
		} else if (a[i] <= y) {
			y = a[i]; // extend second subsequence, no new increase
		} else {
			// a[i] is greater than both tails: we must start a new group in one subsequence,
			// which contributes +1 to the penalty.
			x = a[i];
			ans++;
		}
	}

	cout << ans << '\n';
}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}

// Time Complexity (TC): O(n)
// Space Complexity (SC): O(1)
