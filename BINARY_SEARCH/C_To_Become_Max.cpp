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

int n, k;
vi a;

bool check(int x) {
		// Try every starting index i as the leftmost position of a "ramp" descending by 1 to the right, peaking at x.
		for (int i = 0; i < n; i++) {
				ll cost = 0; // total increments needed to realize a ramp that reaches value x at index i
				// j walks to the right, y denotes the required value at position j if the ramp starts at i with height x
				for (int j = i, y = x; j < n; j++, y--) {
						// If current element already meets the required height, the ramp can "merge" here and we stop.
						if (y <= a[j]) break;
						// If we are at the last element and still short, this start i cannot achieve x; mark as impossible.
						if (j == n - 1) cost += (int)1e9; // sentinel large cost to fail the check
						else cost += (y - a[j]); // number of increments needed at position j to reach y
				}
				// If total needed operations do not exceed k, x is achievable from some i.
				if (cost <= k) return true;
		}
		return false;
}
// ---------- Solve ----------
void solve()
{
  cin >> n >> k;
  a.resize(n);
  rv(a);

  long long l = *max_element(begin(a), end(a));
  long long r = l + (long long)k + n;
  long long ans = l;

  while (l <= r)
  {
    long long mid = (l + r) >> 1;
    if (check(mid))
    {
      ans = mid;
      l = mid + 1;
    }
    else
    {
      r = mid - 1;
    }
  }
  cout << ans << "\n";
}

// ---------- Main ----------
int main()
{
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}