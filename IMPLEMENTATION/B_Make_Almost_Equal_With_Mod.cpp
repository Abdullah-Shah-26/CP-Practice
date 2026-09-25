#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;

	// Loop over each test case
	while (t--) { // Time Complexity: O(t * (N log N))
		int n;
		cin >> n;

		// Array to store the elements of the test case
		long long arr[n];

		// Read the elements into the array
		for (int i = 0; i < n; i++)
			cin >> arr[i]; // Time Complexity: O(N)

		// Variable to store the answer for the current test case
		long long ans = 0;

		// Iterate over powers of 2 from 2^1 to 2^60
		for (int i = 1; i <= 60; i++) { // 2^1 -> 2^60
			// Time Complexity: O(60) -> O(1)

			// Set to store distinct values after mod operation
			set<long long> distinctVals;
			// Calculate k as 2^i
			long long k = 1LL << i; // Time Complexity: O(1)

			// Calculate a[i] % k for each element and insert into the set
			for (int ind = 0; ind < n; ind++) {
				distinctVals.insert(arr[ind] % k); // Time Complexity: O(log N)
			} // Time Complexity: O(N log N)

			// Check if there are exactly 2 distinct values
			if (distinctVals.size() == 2) {
				ans = k;
				break;
			}
		} // Time Complexity: O(N log N)

		// Output the answer for the current test case
		cout << ans << endl;
	}
}

// Total Time Complexity: O(t * (N log N))
// Total Space Complexity: O(t * N)
