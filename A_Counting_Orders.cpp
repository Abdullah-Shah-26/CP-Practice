#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD (ll)(1e9+7)

void solve() {
	int n;
	cin >> n;

	// Read array a of size n
	vector<int> a(n);
	for (int i = 0; i < n; i++) { // O(n)
		cin >> a[i];
	}

	// Sort array a in ascending order
	sort(a.begin(), a.end()); // O(nlogn)

	// Read array b of size n
	vector<int> b(n);
	for (int i = 0; i < n; i++) { // O(n)
		cin >> b[i];
	}

	// Sort array b in descending order
	sort(b.rbegin(), b.rend()); // O(nlogn)

	ll result = 1;

	// Calculate the number of ways to reorder array a
	for (int i = 0; i < n; i++) { // O(nlogn)
		// Find the number of elements in a that are greater than b[i]
		ll temp = upper_bound(a.begin(), a.end(), b[i]) - a.begin();
		ll count = a.size() - temp;

		// Update the result with the number of valid positions for a[i]
		result = result * max(count - i, 0LL) % MOD;
	}

	// Output the result for the current test case
	cout << result << endl;

	// Time Complexity (TC): O(nlogn)
	// Space Complexity (SC): O(n)
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("Error.txt", "w", stderr);
#endif

	int t = 1;
	cin >> t;

	// Process each test case
	while (t--) {
		solve();
	}
}
