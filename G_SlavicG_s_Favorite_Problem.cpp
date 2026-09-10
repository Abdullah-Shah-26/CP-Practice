#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--) {
		int n, a, b;
		cin >> n >> a >> b;
		--a;
		--b;

		vector<vector<pair<int, int>>> adj(n);
		for (int i = 0; i < n - 1; i++) {
			int x, y, w;
			cin >> x >> y >> w;
			--x;
			--y;
			adj[x].push_back({y, w});
			adj[y].push_back({x, w});
		}

		// DFS that accumulates XOR-from-root values in v.
		// If stop != -1, it will not enter the node == stop (i.e., prunes that branch).
		auto dfs = [&](auto &&self, int x, int p, int xr, vector<int> &v, int stop = -1) -> void {
			if (x == stop) return; // do not mark/expand the stop node
			v[x] = xr;            // record XOR-of-weights from the DFS root to x
			for (auto &[y, w] : adj[x]) {
				if (y == p) continue;
				self(self, y, x, (xr ^ w), v, stop);
			}
		};

		vector<int> v1(n, -1), v2(n, -1);
		dfs(dfs, a, -1, 0, v1, b); // XOR from a, but do not traverse into b (cannot pass through b before finishing)
		dfs(dfs, b, -1, 0, v2);    // XOR from b to every node

		bool ans = (v1[b] == 0); // intends to check direct a->b path has XOR 0 (note: v1[b] stays -1 due to pruning above)

		set<int> s; // store all XORs reachable from b (teleport target cannot be b itself)
		for (int i = 0; i < n; i++) {
			if (i == b || v2[i] == -1) continue;
			s.insert(v2[i]);
		}

		// If there exists a node reachable from a (without touching b) whose XOR equals
		// some XOR-from-b value, we can teleport to that b-side node and then enter b with x = 0.
		for (int i = 0; i < n; i++) {
			if (v1[i] != -1 && s.count(v1[i])) ans = true;
		}

		cout << (ans ? "YES\n" : "NO\n");
	}

	return 0;
}

// Time Complexity per test case: O(n log n) due to set insert/find over up to n values
// Space Complexity per test case: O(n) for adjacency, XOR arrays, and the set
    