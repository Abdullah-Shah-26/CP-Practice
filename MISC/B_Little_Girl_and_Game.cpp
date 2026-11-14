#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using vs = vector<string>;
using vb = vector<bool>;
using vvb = vector<vector<bool>>;
using vpii = vector<pii>;
using vvpii = vector<vector<pii>>;
using vpll = vector<pll>;
using vvpll = vector<vector<pll>>;
using T = tuple<ll, ll, ll>;

const int INF = 1e9;
const ll LINF = 4e18;
const int MOD = 1e9 + 7;

static const auto fastio = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}();

#define rv(a) \
  for (auto& x : (a)) cin >> x
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define pb push_back
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define endl '\n'

/*
==========================



==========================
*/

bool isPali(int i, int j, string& s) {
  while (i <= j) {
    if (s[i] == s[j]) {
      i++;
      j--;
    } else
      return false;
  }
  return true;
}

int dp[1001][1001];
int f(int l, int r, string& s) {
  if (l >= r) return 0;
  if (dp[l][r] != -1) return dp[l][r];
  if (s[l] == s[r]) return dp[l][r] = f(l + 1, r - 1, s);
  return dp[l][r] = 1 + min(f(l + 1, r, s), f(l, r - 1, s));
}

void solve() {
  string s;
  cin >> s;

  int n = s.size();

  if (isPali(0, n - 1, s)) {
    cout << "First" << endl;
    return;
  }

  memset(dp, -1, sizeof(dp));

  int cost = f(0, n - 1, s);

  if (cost % 2 == 0)
    cout << "First" << endl;
  else
    cout << "Second" << endl;
}

void solve2() {
  string s;
  cin >> s;

  vi freq(26, 0);

  for (char& ch : s) {
    freq[ch - 'a']++;
  }

  int odd = 0;
  for (int f : freq) odd += f & 1;

  cout << ((odd == 0 || odd % 2 == 1) ? "First" : "Second") << "\n";
}

int main() {
  int t = 1;

  while (t--) {
    solve2();
  }

  return 0;
}