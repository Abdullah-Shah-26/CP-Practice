#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAX = 100000;

void solve() {
    int N;
    cin >> N;

    vector<int> arr(N);

    for (auto& x : arr)
        cin >> x;

    sort(arr.begin(), arr.end());

    // SPF
    vector<int> prime(MAX + 1);

    for (int i = 2; i <= MAX; i++) {
        if (!prime[i]) {

            for (int j = i; j <= MAX; j += i) {

                if (!prime[j])
                    prime[j] = i;
            }
        }
    }

    // count values on left
    vector<int> freq(MAX + 1);

    for (int i = 0; i < N - 1; i++)
        freq[arr[i]]++;

    // cnt[d]
    // numbers divisible by d
    vector<int> cnt(MAX + 1);

    for (int d = 1; d <= MAX; d++) {

        for (int v = d; v <= MAX; v += d)
            cnt[d] += freq[v];
    }

    vector<ll> dp(MAX + 1);

    vector<int> ts(MAX + 1);

    int timer = 0;

    for (int t = N - 2; t > 0; t--) {

        timer++;

        int val = arr[t];

        vector<int> primes;

        while (val > 1) {

            int p = prime[val];

            primes.push_back(p);

            while (val % p == 0)
                val /= p;
        }

        queue<int> q;

        q.push(arr[t]);

        ts[arr[t]] = timer;

        while (!q.empty()) {

            val = q.front();

            q.pop();

            dp[val] +=
                1LL *
                (cnt[val] - 1) *
                (N - t - 1);

            cnt[val]--;

            for (int p : primes) {

                if (p > prime[val])
                    break;

                int next = val / p;

                if (next * p != val)
                    continue;

                if (ts[next] == timer)
                    continue;

                ts[next] = timer;

                q.push(next);
            }
        }
    }

    ll ans = 0;

    for (int i = 1; i <= MAX; i++)
        ans += dp[i];

    cout << ans << '\n';
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;

    cin >> T;

    while (T--)
        solve();

    return 0;
}