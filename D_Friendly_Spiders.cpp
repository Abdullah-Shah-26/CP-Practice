#include <bits/stdc++.h>
using namespace std;

const int MAXA = 300000;

// spf[x] will store the smallest prime that divides x
vector<int> spf(MAXA + 1);
void sieve() {
  // initialize spf[i] = i
  iota(spf.begin(), spf.end(), 0);
  for (int i = 2; i * i <= MAXA; i++)
    if (spf[i] == i)  // i is prime
      for (int j = i * i; j <= MAXA; j += i)
        if (spf[j] == j)
          spf[j] = i;  // first time we set, it's the smallest prime factor
}

// Returns the list of distinct prime factors of x using precomputed spf
vector<int> factorize(int x) {
  vector<int> primes;
  while (x > 1) {
    int p = spf[x];
    primes.push_back(p);
    while (x % p == 0) x /= p;  // skip duplicates of the same prime
  }
  return primes;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  sieve();

  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) cin >> a[i];

  int s, t;
  cin >> s >> t;

  if (s == t) {  // trivial case: already at destination
    cout << 1 << "\n" << s << "\n";
    return 0;
  }

  // For each prime p, store indices of spiders whose a[i] is divisible by p
  vector<vector<int>> spiders_by_prime(MAXA + 1);
  for (int i = 1; i <= n; i++) {
    for (int p : factorize(a[i])) spiders_by_prime[p].push_back(i);
  }

  vector<int> dist(n + 1, -1), parent(n + 1, -1);
  vector<bool> prime_used(
      MAXA + 1, false);  // ensure each prime bucket is expanded at most once
  queue<int> q;

  dist[s] = 0;
  q.push(s);

  while (!q.empty()) {
    int u = q.front();
    q.pop();

    // All neighbors of u can be found by expanding prime buckets of a[u]
    for (int p : factorize(a[u])) {
      if (prime_used[p]) continue;  // already expanded this prime bucket
      prime_used[p] = true;
      for (int v : spiders_by_prime[p]) {
        if (dist[v] == -1) {  // visit v for the first time
          dist[v] = dist[u] + 1;
          parent[v] = u;
          q.push(v);
          if (v == t) break;  // we found t; allow outer BFS to finish quickly
        }
      }
    }
  }

  if (dist[t] == -1) {  // unreachable
    cout << -1 << "\n";
    return 0;
  }

  // Reconstruct path from t back to s using parent links
  vector<int> path;
  for (int v = t; v != -1; v = parent[v]) path.push_back(v);
  reverse(path.begin(), path.end());

  cout << path.size() << "\n";
  for (int i = 0; i < (int)path.size(); i++)
    cout << path[i] << " \n"[i + 1 == (int)path.size()];
}
