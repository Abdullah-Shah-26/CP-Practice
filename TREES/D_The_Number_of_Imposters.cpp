#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n, m;                       // number of players and comments
vector<vector<int>> adj;        // adjacency list (real nodes [0..n-1], fake nodes [n..))
vector<int> col;                // 0 = uncolored, 1/2 = bipartite colors
int pos, c1, c2, ans;           // pos: feasibility flag, c1/c2: counts per color (real nodes only), ans: result sum

// DFS to 2-color the graph so that every edge connects nodes of opposite colors
void dfs(int x) {
	// Count only real players (indices < n); fake nodes are helpers for constraints
	if (x < n) {
		if (col[x] == 1)
			c1++;
		else
			c2++;
	}

	int next_col = (col[x] == 1 ? 2 : 1);  // neighbors must have opposite color
	for (auto &y : adj[x]) {
		if (col[y]) {                       // already colored neighbor
			if (col[y] != next_col)
				pos = 0;                     // conflict -> constraints contradict each other
			continue;
		}
		col[y] = next_col;
		dfs(y);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n >> m;
		// Reserve up to n + m nodes (worst-case: one fake node per comment)
		adj = vector<vector<int>>(n + m);
		for (int j = 0, fake = n; j < m; j++) {
			int u, v;
			cin >> u >> v;
			u--, v--;                    // switch to 0-based indexing
			string c;
			cin >> c;
			if (c == "imposter") {
				// "imposter" means roles of u and v must be different -> direct edge enforces opposite colors
				adj[u].push_back(v);
				adj[v].push_back(u);
			} else {
				// "crewmate" means roles must be the same. Enforce via a fake node connected by "different" edges:
				// u - fake and v - fake with opposite colors -> u and v end up with the same color.
				adj[u].push_back(fake);
				adj[fake].push_back(u);
				adj[v].push_back(fake);
				adj[fake].push_back(v);
				fake++;
			}
		}

		col = vector<int>(n + m, 0);
		ans = 0;
		pos = 1;
		for (int i = 0; i < n; i++) {
			if (col[i])
				continue;                 // already visited in some previous component
			c1 = c2 = 0;
			col[i] = 1;                  // start this component with color 1
			dfs(i);
			ans += max(c1, c2);          // choose the better labeling for this component
		}

		if (!pos)
			ans = -1;                    // contradiction detected
		cout << ans << "\n";
	}

	return 0;
}

/*
Time Complexity (per test case): O(n + m)
Space Complexity (per test case): O(n + m)
*/
