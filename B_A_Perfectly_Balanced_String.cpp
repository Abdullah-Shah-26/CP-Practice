#include <bits/stdc++.h>
using namespace std;

void solve() {
	string s;
	cin >> s; // Read the input string
	int n = (int)s.size(); // Get the length of the string
	set<char> c; // Set to store unique characters
	int k;
	// Loop to find the first repeating character
	for (k = 0; k < n; k++) { // O(n log n) due to set operations
		if (c.find(s[k]) == c.end()) {
			c.insert(s[k]); // Insert character into the set if not found
		} else {
			break; // Break if a repeating character is found
		}
	}
	// Check if the string is perfectly balanced
	for (int i = k; i < n; i++) { // O(n)
		if (s[i] != s[i - k]) {
			cout << "NO" << endl; // Output NO if the condition fails
			return;
		}
	}
	cout << "YES" << endl; // Output YES if the string is perfectly balanced
}

// Time Complexity (TC): O(n log n)
// Space Complexity (SC): O(n)

int main() {
#ifndef ONLINE_JUDGE
	freopen("Error.txt", "w", stderr);
#endif
	int t = 1;
	cin >> t; // Read the number of test cases
	while (t--) {
		solve(); // Solve each test case
	}
}
