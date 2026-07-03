#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
// using namespace __gnu_pbds;

// // ---------- PBDS Ordered Set ----------
// template<typename T>
// using ordered_set = tree<
//     T,
//     null_type,
//     less<T>,
//     rb_tree_tag,
//     tree_order_statistics_node_update>;

// ---------- Type aliases ----------
using ll = long long;
using ull = unsigned long long;

#if defined(__SIZEOF_INT128__)
using lll = __int128;
using ulll = unsigned __int128;
#endif

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

// ---------- Solve ----------
void solve()
{
  int n, q;
  cin >> n >> q;

  vi a(n);
  rv(a);

  vector<long long> events(n, 0);

  while (q--)
  {
    int l, r;
    cin >> l >> r;
    l--;
    r--;

    events[l] += 1;
    if (r + 1 < n)
      events[r + 1] -= 1;
  }

  // Cumulative sum
  for (int i = 1; i < n; i++)
  {
    events[i] += events[i - 1];
  }

  sort(begin(a), end(a), greater<int>());
  sort(begin(events), end(events), greater<long long>());

  long long res = 0;
  for (int i = 0; i < n; i++)
    res += 1LL * events[i] * a[i];

  cout << res << "\n";
}

// ---------- Main ----------
int main()
{
  solve();
  return 0;
}