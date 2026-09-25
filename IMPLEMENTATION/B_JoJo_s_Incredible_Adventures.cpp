#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Function to solve each test case
void solve() {
	string s;
	cin >> s; // Read the binary string
	ll n = s.size(); // Get the length of the string
	ll maxi = 0; // Variable to store the maximum length of consecutive '1's
	ll i = 0;

	// Iterate over the string to find the longest sequence of '1's
	while (i < n) { // Loop through the string
		if (s[i] == '0') { // If the current character is '0', move to the next character
			i++;
			continue;
		}
		ll j = i + 1;
		while (j < n && s[j] == '1') { // Count consecutive '1's
			j++;
		}
		maxi = max(maxi, j - i); // Update the maximum length
		i = j; // Move to the next segment
	}

	// If the entire string is '1's, the area is n*n
	if (maxi == n) {
		cout << 1LL * n * n << endl;
		return;
	}

	// Check if the string starts and ends with '1'
	if (s[0] == '1' && s[n - 1] == '1') {
		ll i = 0;
		ll cnt = 0;
		while (i < n && s[i] == '1') { // Count '1's from the start
			i++;
			cnt++;
		}
		ll j = n - 1;
		while (j > i && s[j] == '1') { // Count '1's from the end
			j--;
			cnt++;
		}
		maxi = max(maxi, cnt); // Update the maximum length
	}

	maxi++; // Increment the maximum length by 1
	ll temp = (maxi + 1) / 2; // Calculate half of the incremented length
	cout << (temp) * (maxi / 2) << endl; // Calculate and print the maximum area

	// Time Complexity (TC): O(n)
	// Space Complexity (SC): O(n)
}

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
