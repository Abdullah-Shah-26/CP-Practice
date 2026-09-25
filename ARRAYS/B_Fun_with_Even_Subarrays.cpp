#include <bits/stdc++.h>
using namespace std;

int main() {
	#ifndef ONLINE_JUDGE
		freopen("Error.txt", "w", stderr);
	#endif

	int t;
	cin >> t; // Read the number of test cases
	while (t--) {
		int n;
		cin >> n; // Read the length of the array for the current test case
		vector<int> v(n); // Initialize a vector to store the array elements
		for (int i = 0; i < n; i++) {
			cin >> v[i]; // Read each element of the array
		}

		int ans = 0; // Initialize the answer (number of operations) to 0
		int i = n - 1; // Start from the last element of the array

		// Move i backwards until we find an element different from the last element
		while (i >= 0 && v[i] == v[n - 1]) {
			i--;
		}

		// If all elements are the same as the last element, no operations are needed
		if (i == -1) {
			cout << 0 << endl;
			continue;
		}

		// Perform operations until all elements are equal
		while (i >= 0) {
			i -= (n - 1 - i); // Move i backwards by the size of the subarray
			ans++; // Increment the number of operations

			// Move i backwards until we find an element different from the last element
			while (i >= 0 && v[i] == v[n - 1]) {
				i--;
			}
		}

		cout << ans << endl; // Output the number of operations needed
	}

	// Time Complexity (TC): O(n)
	// Space Complexity (SC): O(n)
}
