#include <bits/stdc++.h>
using namespace std;

int main() {
		int tc;
		cin >> tc;
		while (tc--) {
				int n;
				cin >> n;

				int l = 1, r = n; // search space for the fixed point's index/value (they are equal at the fixed point)
				while (l < r) {
						int mid = (l + r) / 2;

						// Query the judge for the sorted contents of a[l..mid]
						cout << "? " << l << " " << mid << endl;
						cout.flush(); // mandatory in interactive problems to ensure the query is sent

						int cnt = 0; // how many numbers in the answer fall into [l, mid]
						// We will receive (mid - l + 1) numbers: the sorted subarray a[l..mid]
						for (int i = 0; i < (mid - l + 1); i++) {
								int x;
								cin >> x;
								// Order doesn't matter for our check: only membership in [l, mid]
								if (l <= x && x <= mid) cnt++;
						}

						// Key idea: every element in [l..mid] is paired (swapped) except possibly the fixed point.
						// Therefore, the count of values from [l..mid] appearing in a[l..mid] is odd iff
						// the fixed point lies in [l..mid]. Otherwise it's even and the fixed point is in (mid..r].
						if (cnt % 2) {
								r = mid;
						} else {
								l = mid + 1;
						}
				}

				// l (== r) is the value/index of the fixed point
				cout << "! " << l << endl;
				cout.flush();
		}

		return 0;
}

// Time Complexity per test case: O(n) (the total length of queried segments sums to < 2n)
// Space Complexity per test case: O(1) extra space
