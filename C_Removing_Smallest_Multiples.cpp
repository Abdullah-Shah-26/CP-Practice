#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t; // Read the number of test cases

	while (t--)
	{
		int n;
		cin >> n; // Read the size of the set S

		string s;
		cin >> s; // Read the binary string representing set T

		long long ans = 0; // Initialize the total cost to 0

		// Vector to keep track of removed elements, initialized to false
		vector<bool> isRemoved(n + 1, false);

		// Iterate over each possible k from 1 to n
		for (int i = 1; i <= n; i++)
		{
			// Iterate over multiples of k
			for (int j = i; j <= n; j += i)
			{
				// If the current position in T is '1', stop further deletions
				if (s[j - 1] == '1')
					break;

				// If the element is already removed, continue
				if (isRemoved[j])
					continue;
				else
				{
					// Mark the element as removed and add the cost
					isRemoved[j] = true;
					ans += i;
				}
			}
		} // End of O(n log n) loop

		cout << ans << "\n"; // Output the minimum cost for the current test case
	}

	return 0;
}

// Time Complexity (TC): O(n log n)
// Space Complexity (SC): O(n)
