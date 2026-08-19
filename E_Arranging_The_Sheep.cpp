#include <bits/stdc++.h>
using namespace std;

void solve() {
		int n;
		cin >> n;
		string s;
		cin >> s;

		vector<int> sheeps; // positions (indices) of all sheep ('*') in the string

		for (int i = 0; i < n; i++) {
				if (s[i] == '*') {
						sheeps.push_back(i); // collect the index of each sheep
				}
		}

		// Index of the median sheep among collected positions. Using the median
		// minimizes total distance when aligning to consecutive positions.
		// If there are no sheep, the loop below won't run, so this value isn't used.
		int index = (sheeps.size() - 1) / 2;

		long long ans = 0; // accumulate total moves; use 64-bit to avoid overflow

		// Target arrangement: make sheep occupy consecutive cells centered around
		// the median sheep. Base position = sheeps[index] - index, so the i-th
		// sheep's target is (base + i). Sum absolute shifts to get minimal moves.
		for (int i = 0; i < sheeps.size(); i++) {
				ans += abs(sheeps[i] - (sheeps[index] - index + i));
		}

		cout << ans << '\n';
}

int main() {
		cin.sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		int t;
		cin >> t;

		while (t--) {
				solve();
		}
}

/*
Time Complexity (TC): O(n)
Space Complexity (SC): O(n)
*/
