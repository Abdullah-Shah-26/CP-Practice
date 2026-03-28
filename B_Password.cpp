#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

static const int MOD = 1'000'000'007;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }


vector<int> buildZ(const string& s) {
    int n = s.size();
    vector<int> Z(n);
    int L = 0, R = 0;

    for (int i = 1; i < n; i++) {
        if (i <= R)
            Z[i] = min(R - i + 1, Z[i - L]);

        while (i + Z[i] < n && s[Z[i]] == s[i + Z[i]])
            Z[i]++;

        if (i + Z[i] - 1 > R) {
            L = i;
            R = i + Z[i] - 1;
        }
    }
    return Z;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    int n = s.size();

    vector<int> Z = buildZ(s);

    // prefMax[i] = maximum Z value seen from index 1 to i
    vector<int> prefMax(n);
    for (int i = 1; i < n; i++)
        prefMax[i] = max(prefMax[i-1], Z[i]);

    int bestLen = 0;

    for (int i = 1; i < n; i++) {
        int L = Z[i];

        // check if prefix of length L is also suffix
        if (i + L == n) {
            // check if appears somewhere in middle
            if (prefMax[i-1] >= L)
                bestLen = max(bestLen, L);
        }
    }

    if (bestLen == 0)
        cout << "Just a legend";
    else
        cout << s.substr(0, bestLen);

    return 0;
}
