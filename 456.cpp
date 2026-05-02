#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int cnt[3][7] = {};

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 6; j++) {
            int x;
            cin >> x;
            cnt[i][x]++;
        }
    }

    vector<int> v = {4, 5, 6};
    double good = 0;

    sort(v.begin(), v.end());

    do {
        good += 1.0 * cnt[0][v[0]] * cnt[1][v[1]] * cnt[2][v[2]];
    } while (next_permutation(v.begin(), v.end()));

    cout << fixed << setprecision(10) << good / 216.0 << '\n';
}