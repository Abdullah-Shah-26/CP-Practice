#include <bits/stdc++.h>

using namespace std;

// ---------- Type aliases ----------
using ll = long long;
using ull = unsigned long long;
using ld = long double;

using pi = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using vs = vector<string>;
using vb = vector<bool>;
using vpi = vector<pi>;
using vvpi = vector<vector<pi>>;

// ---------- Constants ----------
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;

// ---------- Fast IO ----------
static const auto fastio = []()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}();

// ---------- GCD / LCM ----------
int gcd_int(int a, int b)
{
  while (b)
  {
    a %= b;
    swap(a, b);
  }
  return a;
}
int lcm_int(int a, int b) { return a / gcd_int(a, b) * b; }
ll gcdll(ll a, ll b)
{
  while (b)
  {
    a %= b;
    swap(a, b);
  }
  return a;
}
ll lcmll(ll a, ll b) { return a / gcdll(a, b) * b; }

// ---------- Modular arithmetic ----------
ll mod_pow(ll a, ll b, ll m = MOD)
{
  ll res = 1;
  while (b)
  {
    if (b & 1)
      res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
ll mod_inv(ll a, ll m = MOD) { return mod_pow(a, m - 2, m); }
ll mod_add(ll a, ll b, ll m = MOD) { return (a % m + b % m) % m; }
ll mod_sub(ll a, ll b, ll m = MOD) { return (a % m - b % m + m) % m; }
ll mod_mul(ll a, ll b, ll m = MOD) { return (a % m * b % m) % m; }

// ---------- Bit helpers ----------
int bitcount(ll x) { return __builtin_popcountll(x); }
int msb_index(ll x) { return 63 - __builtin_clzll(x); }
int lsb_index(ll x) { return __builtin_ctzll(x); }

// ---------- Divisors ----------
vector<ll> get_divisors(ll n)
{
  vector<ll> d;
  for (ll i = 1; i * i <= n; i++)
  {
    if (n % i == 0)
    {
      d.push_back(i);
      if (i * i != n)
        d.push_back(n / i);
    }
  }
  sort(d.begin(), d.end());
  return d;
}

// ---------- Prefix sum ----------
vector<ll> prefix_sum(const vector<ll> &a)
{
  int n = a.size();
  vector<ll> pref(n + 1, 0);
  for (int i = 0; i < n; i++)
    pref[i + 1] = pref[i] + a[i];
  return pref;
}

// ---------- Suffix sum ----------
vector<ll> suffix_sum(const vector<ll> &a)
{
  int n = a.size();
  vector<ll> suff(n + 1, 0);
  for (int i = n - 1; i >= 0; i--)
    suff[i] = suff[i + 1] + a[i];
  return suff;
}

// ---------- 2D Prefix ----------
vector<vector<ll>> prefix2D(const vector<vector<ll>> &a)
{
  int n = a.size(), m = a[0].size();
  vector<vector<ll>> p(n + 1, vector<ll>(m + 1, 0));
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      p[i][j] = a[i - 1][j - 1] + p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1];
  return p;
}

// ---------- Min/Max update ----------
template <class T>
bool chmax(T &a, T b)
{
  if (b > a)
  {
    a = b;
    return true;
  }
  return false;
}
template <class T>
bool chmin(T &a, T b)
{
  if (b < a)
  {
    a = b;
    return true;
  }
  return false;
}

// ---------- Z Algorithm ----------
vector<int> buildZ(string &s)
{
  int n = s.size();
  vector<int> Z(n);
  int l = 0, r = 0;
  for (int i = 1; i < n; i++)
  {
    if (i <= r)
      Z[i] = min(r - i + 1, Z[i - l]);
    while (i + Z[i] < n && s[Z[i]] == s[i + Z[i]])
      Z[i]++;
    if (i + Z[i] - 1 > r)
    {
      l = i;
      r = i + Z[i] - 1;
    }
  }
  return Z;
}

// ---------- KMP ----------
void computeLPS(const string &pat, vector<int> &lps)
{
  int m = pat.size();
  lps.assign(m, 0);
  int len = 0;
  for (int i = 1; i < m; i++)
  {
    while (len > 0 && pat[i] != pat[len])
      len = lps[len - 1];
    if (pat[i] == pat[len])
      len++;
    lps[i] = len;
  }
}

bool findPattern(const string &pat, const string &txt)
{
  int n = txt.size(), m = pat.size();
  vector<int> lps;
  computeLPS(pat, lps);
  int j = 0;
  for (int i = 0; i < n; i++)
  {
    while (j > 0 && txt[i] != pat[j])
      j = lps[j - 1];
    if (txt[i] == pat[j])
      j++;
    if (j == m)
      return true;
  }
  return false;
}

// ---------- Macros ----------
#define rv(a)         \
  for (auto &x : (a)) \
  cin >> x
#define rm(mat)         \
  for (auto &r : (mat)) \
    for (auto &x : (r)) \
  cin >> x
#define pb push_back
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define per(i, a, b) for (int i = (b) - 1; i >= (a); --i)

const int MAXN = 100005;
const int LOG = 18;

vector<int> adj[MAXN];
int ancestors[MAXN][LOG];
int depth[MAXN];
int sub[MAXN]; // Subtree Sizes
int n;

void dfs(int v, int p)
{
  ancestors[v][0] = p;
  sub[v] = 1;

  for (int i = 1; i < LOG; i++)
  {
    ancestors[v][i] = ancestors[ancestors[v][i - 1]][i - 1];
  }

  for (int to : adj[v])
  {
    if (to != p)
    {
      depth[to] = depth[v] + 1;
      dfs(to, v);
      sub[v] += sub[to];
    }
  }
}
//* After DFS we know
// 1 Parent of every node
// 2 Binary Lifting Table
// 3 Subtree Size
// 4 Depth of Every Node

int jump(int node, int k)
{
  for (int i = 0; i < LOG; i++)
  {
    if (k & (1 << i))
    {
      node = ancestors[node][i];
    }
  }
  return node;
}

int lca(int a, int b)
{
  if (depth[a] < depth[b])
    swap(a, b);

  a = jump(a, depth[a] - depth[b]);

  if (a == b)
    return a;

  per(i, LOG, 0)
  {
    if (ancestors[a][i] != ancestors[b][i])
    {
      a = ancestors[a][i];
      b = ancestors[b][i];
    }
  }
  return ancestors[a][0];
}

int dist(int a, int b)
{
  int LCA = lca(a, b);
  return depth[a] + depth[b] - 2 * depth[LCA];
}

int solveQuery(int x, int y)
{
  if (x == y)
  {
    return n;
  }

  int d = dist(x, y);
  if (d & 1)
  { // Odd dist No Integer Midpt No Equidistance Node
    return 0;
  }

  if (depth[x] == depth[y])
  {
    // Midpt is LCA
    int childX = jump(x, d / 2 - 1);
    int childY = jump(y, d / 2 - 1);

    return n - sub[childX] - sub[childY];
  }
  // Diff depths - Midpt is on one side of LCA
  // Always make x deeper node
  if (depth[x] < depth[y])
  {
    swap(x, y);
  }

  int mid = jump(x, d / 2);
  int childTowardsX = jump(x, d / 2 - 1);

  return sub[mid] - sub[childTowardsX];
}

// ---------- Solve ----------
void solve()
{
  cin >> n;

  for (int i = 0; i < n - 1; i++)
  {
    int a, b;
    cin >> a >> b;

    adj[a].pb(b);
    adj[b].pb(a);
  }

  for (int i = 0; i < LOG; i++)
    ancestors[1][i] = 1;

  dfs(1, 1);

  int q;
  cin >> q;

  while (q--)
  {
    int x, y;
    cin >> x >> y;

    cout << solveQuery(x, y) << "\n";
  }
}

// ---------- Main ----------
int main()
{
  // int t;
  // cin>>t;
  // while(t--)
  solve();
  return 0;
}