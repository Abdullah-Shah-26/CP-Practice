#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main() {
		ios::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		int t;
		cin >> t;
		while (t--) {
				int n;
				cin >> n;
				vector<int> a(n);
				for (auto &i : a)
						cin >> i; // read monsters in each horde

				int sum = accumulate(a.begin(), a.end(), 0LL); // total monsters across all hordes
				int rem = sum / 2; // how many monsters we aim to remove via second-type attacks (roughly half)
				int ans = sum - rem; // baseline: ceil(sum/2) first-type attacks if no/limited dumps

				sort(a.rbegin(), a.rend()); // dump combo into largest hordes first to satisfy "at least x" constraint
				for (auto x : a) {
						if (rem <= 0)
								break; // enough capacity gathered for dumps
						rem -= x; // use this horde to absorb one second-type attack worth up to x
						ans++; // one additional second-type attack used on this horde
				}

				cout << ans << '\n';
		}

		return 0;
}

/*
Time Complexity (TC): O(nlogn)
Space Complexity (SC): O(n)
*/
