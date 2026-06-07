#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Function to solve each test case
void solve() {
	ll n; // Number of teleporters
	cin >> n;
	ll c; // Number of coins available
	cin >> c;
	vector<ll> cost; // Vector to store the effective cost of using each teleporter

	// Read the cost of each teleporter and calculate the effective cost
	for (int i = 1; i <= n; i++) { // Loop through each teleporter
		ll x;
		cin >> x; // Cost to use teleporter at position i
		cost.push_back(i + x); // Effective cost includes moving to position i
	}

	// Sort the costs in ascending order to use the cheapest teleporters first
	sort(cost.begin(), cost.end());

	int i = 0; // Index to iterate through the sorted costs
	int ans = 0; // Counter for the number of teleporters used

	// Use teleporters while there are enough coins
	while (i < n && cost[i] <= c) {
		c -= cost[i]; // Deduct the cost from the available coins
		ans++; // Increment the count of teleporters used
		i++; // Move to the next teleporter
	}

	cout << ans << endl; // Output the maximum number of teleporters used

	// Time Complexity (TC): O(nlogn)
	// Space Complexity (SC): O(n)
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("Error.txt", "w", stderr);
#endif

	int t = 1; // Number of test cases
	cin >> t;
	while (t--) {
		solve(); // Solve each test case
	}
}
