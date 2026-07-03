#include <bits/stdc++.h>

using namespace std;

// ---------- Type aliases ----------
using ll = long long;
using ull = unsigned long long;
using ld = long double;

using pi = pair<int,int>;
using pll = pair<ll,ll>;
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
static const auto fastio = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

// ---------- GCD / LCM ----------
int gcd_int(int a,int b){ while(b){ a%=b; swap(a,b);} return a; }
int lcm_int(int a,int b){ return a/gcd_int(a,b)*b; }
ll gcdll(ll a,ll b){ while(b){ a%=b; swap(a,b);} return a; }
ll lcmll(ll a,ll b){ return a/gcdll(a,b)*b; }

// ---------- Modular arithmetic ----------
ll mod_pow(ll a,ll b,ll m=MOD){
    ll res=1;
    while(b){
        if(b&1) res=res*a%m;
        a=a*a%m;
        b>>=1;
    }
    return res;
}
ll mod_inv(ll a,ll m=MOD){ return mod_pow(a,m-2,m); }
ll mod_add(ll a,ll b,ll m=MOD){ return (a%m+b%m)%m; }
ll mod_sub(ll a,ll b,ll m=MOD){ return (a%m-b%m+m)%m; }
ll mod_mul(ll a,ll b,ll m=MOD){ return (a%m*b%m)%m; }

// ---------- Bit helpers ----------
int bitcount(ll x){ return __builtin_popcountll(x); }
int msb_index(ll x){ return 63-__builtin_clzll(x); }
int lsb_index(ll x){ return __builtin_ctzll(x); }

// ---------- Divisors ----------
vector<ll> get_divisors(ll n){
    vector<ll> d;
    for(ll i=1;i*i<=n;i++){
        if(n%i==0){
            d.push_back(i);
            if(i*i!=n) d.push_back(n/i);
        }
    }
    sort(d.begin(), d.end());
    return d;
}

// ---------- Prefix sum ----------
vector<ll> prefix_sum(const vector<ll>& a){
    int n=a.size();
    vector<ll> pref(n+1,0);
    for(int i=0;i<n;i++) pref[i+1]=pref[i]+a[i];
    return pref;
}

// ---------- Suffix sum ----------
vector<ll> suffix_sum(const vector<ll>& a){
    int n=a.size();
    vector<ll> suff(n+1,0);
    for(int i=n-1;i>=0;i--) suff[i]=suff[i+1]+a[i];
    return suff;
}

// ---------- 2D Prefix ----------
vector<vector<ll>> prefix2D(const vector<vector<ll>>& a){
    int n=a.size(), m=a[0].size();
    vector<vector<ll>> p(n+1, vector<ll>(m+1,0));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            p[i][j]=a[i-1][j-1]+p[i-1][j]+p[i][j-1]-p[i-1][j-1];
    return p;
}

// ---------- Min/Max update ----------
template<class T> bool chmax(T& a,T b){ if(b>a){ a=b; return true;} return false; }
template<class T> bool chmin(T& a,T b){ if(b<a){ a=b; return true;} return false; }


// ---------- Macros ----------
#define rv(a) for(auto &x:(a)) cin>>x
#define rm(mat) for(auto &r:(mat)) for(auto &x:(r)) cin>>x
#define pb push_back
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)

// ---------- Solve ----------
void solve(){
    string s;
    cin >> s;

    int n = s.size();
    if(n == 1){
      cout  << 0 << "\n";
      return;
    }

    ll sum = 0;
    for(char c : s){
      sum += (c - '0');
    }

    if(sum <= 9){
      cout << 0 << "\n";
      return;
    }

    ll needToReduce = sum - 9;

    vi reduce;
    reduce.pb((s[0] - '0') - 1); // Cannot make first No as 0 so Ex : If 2 we can only reduce it by 1 

    rep(i, 1, n ){
      reduce.pb(s[i]-'0');
    }

    sort(reduce.rbegin(), reduce.rend());

    ll moves = 0;

    for(int r : reduce){
      needToReduce -= r;
      moves++;
      if(needToReduce <= 0){
        break;
      }
    }

    cout << moves << "\n";
}

// ---------- Main ----------
int main(){
    int t; 
    cin>>t;
    while(t--)
    solve();
    return 0;
}