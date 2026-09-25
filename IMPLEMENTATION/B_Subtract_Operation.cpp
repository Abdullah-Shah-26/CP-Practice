#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Function to solve each test case
void solve() {
	ll n, k;
	cin >> n >> k; // Read the number of integers in the list and the target value
	vector<ll> v(n); // Declare a vector to store the list of integers

	// Read the list of integers
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	map<ll, bool> mp; // Map to store the presence of each integer in the list

	// Populate the map with the integers from the list
	for (auto it : v) {
		mp[it] = true;
	}

	// Check if there exists an element such that element - k is also in the list
	for (int i = 0; i < n; i++) {
		if (mp.find(v[i] - k) != mp.end()) {
			cout << "YES" << endl; // If found, print "YES"
			return;
		}
	}

	cout << "NO" << endl; // If no such element is found, print "NO"

	// Time Complexity (TC): O(nlogn)
	// Space Complexity (SC): O(n)
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("Error.txt", "w", stderr);
#endif

	int t;
	cin >> t; // Read the number of test cases

	// Solve each test case
	while (t--) {
		solve();
	}
}

  