#include <bits/stdc++.h>

using namespace std;

int main() {
	// Optimize input/output operations
	ios::sync_with_stdio(false), cin.tie(nullptr);

	int t; // Number of test cases
	cin >> t;

	while (t--) {
		int n, x; // n: number of books in each stack, x: Tenzing's favorite number
		cin >> n >> x;

		// Precomputed OR results for each stack
		vector<int> pre[3];

		// Iterate over each stack
		for (int i = 0; i < 3; i++) { // Loop for 3 stacks
			int s = 0; // Initialize current OR result
			pre[i].push_back(s); // Start with 0 OR result

			// Read each book's difficulty in the stack
			for (int j = 0; j < n; j++) {
				int a;
				cin >> a;

				// If adding this book changes the OR result, update it
				if ((s | a) != s) {
					s |= a;
					pre[i].push_back(s);
				}
			}
		}

		bool ans = false; // Flag to check if x can be achieved

		// Check all combinations of OR results from the three stacks
		for (int A : pre[0]) { // Iterate over precomputed OR results of stack 1
			for (int B : pre[1]) { // Iterate over precomputed OR results of stack 2
				for (int C : pre[2]) { // Iterate over precomputed OR results of stack 3
					// Check if the combined OR result equals x
					if ((A | B | C) == x) {
						ans = true;
					}
				}
			}
		}

		// Output the result for the current test case
		cout << (ans ? "YES\n" : "NO\n");
	}

	// Time Complexity (TC): O(max(3*n, (31^3)))
	// Space Complexity (SC): O(3*31)
}
