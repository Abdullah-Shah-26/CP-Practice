#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// Ordered Set
#define oset tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
// order_of_key(k) : No of Elements < k
// *find_by_order(i) : Value at idx i (0 - based)

// ---------- Type aliases ----------
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
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

// ---------- Constants ----------
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;

// ---------- Fast IO ----------
static const auto fastio = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

// ---------- Macros ----------
#define rv(a) for(auto &x:(a)) cin>>x
#define pv(a) do{ for(const auto &x:(a)) cout<<x<<' '; cout<<'\n'; }while(0)
#define rm(mat) for(auto &r:(mat)) for(auto &x:(r)) cin>>x
#define pm(mat) do{ for(const auto &r:(mat)){ for(const auto &x:(r)) cout<<x<<' '; cout<<'\n'; } }while(0)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define pb push_back
#define eb emplace_back
#define rs resize
#define as assign
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define yno(a) cout << ((a) ? "YES\n" : "NO\n")
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define endl '\n'

int n, maxH;
ll x;
vll c,h;
vvll dp;

// Max money saved after months 0...i when targeting H happiness
ll f(int i, int H){
  if(i < 0){
    if(H == 0)
      return 0;
    return -INF;
  }

  if(dp[i][H] != -1)
    return dp[i][H];

  // Skip
  ll m1 = f(i - 1, H) + x;  

  // Take
  ll m2 = -INF;
  if(H - h[i] >= 0){
    ll prevSaved = f(i - 1, H - h[i]);

    if(prevSaved >= c[i])
      m2 = max(m2, prevSaved - c[i] + x);
  }

  return dp[i][H] = max(m1, m2); 
}

// ---------- Solve ---------
void solve(){
  cin >> n >> x;

  c.assign(n,0);
  h.assign(n,0);

  for(int i = 0; i < n; i++)
    cin >> c[i] >> h[i];

  maxH = accumulate(all(h),0LL);
  dp.assign(n, vector<ll>(maxH + 1, -1));

  for(int H = maxH; H >= 0; H--){
    ll saved = f(n - 1, H);
    if(saved >= 0){
      cout << H << endl;
      break;
    }
  }
}

// ---------- Main ----------
int main(){
  int t; 
  cin >> t;
  while(t--)
    solve();
  return 0;
}