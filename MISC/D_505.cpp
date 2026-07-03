#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
// 128-bit integers are supported on GCC/Clang, but not on MSVC.
#if defined(__SIZEOF_INT128__)
using lll = __int128;
using ulll = unsigned __int128;
#endif
using ld = long double;

using pi = pair<int,int>;
using pll = pair<ll,int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using vs = vector<string>;
using vb = vector<bool>;
using vpi = vector<pi>;
using vvpi = vector<vector<pi>>;

const int INF = 1e9;
const int MOD = 1e9 + 7;

static const auto fastio = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

// ---------- GCD / LCM ----------
int gcd_int(int a, int b) {
    while(b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int lcm_int(int a, int b){
    return (a / gcd_int(a,b)) * b;
}

ll gcdll(ll a, ll b){
    while(b){ a%=b; swap(a,b); }
    return a;
}
ll lcmll(ll a, ll b){return (a / gcdll(a,b)) * b;}


// ---------- Modular arithmetic ----------
ll mod_pow(ll a, ll b, ll m = MOD){
    ll res = 1;
    while(b){
        if(b&1) res = (res*a)%m;
        a = (a*a)%m;
        b >>= 1;
    }
    return res;
}
ll mod_inv(ll a, ll m = MOD){ return mod_pow(a, m-2, m); }
ll mod_add(ll a, ll b, ll m = MOD){a %= m; b %= m;return (a + b) % m;}
ll mod_sub(ll a, ll b, ll m = MOD){a %= m; b %= m;return (a - b + m) % m;}
ll mod_mul(ll a, ll b, ll m = MOD){return (a % m * b % m) % m;}


// ---------- Bit helpers ----------
int bitcount(ll x){ return __builtin_popcountll(x); }
int msb_index(ll x){ return 63 - __builtin_clzll(x); }
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
//sum of range [l, r] = pref[r+1] - pref[l]

vector<ll> prefix_sum(const vector<ll>& a){
    int n = a.size();
    vector<ll> pref(n+1, 0);
    for(int i=0;i<n;i++)
        pref[i+1] = pref[i] + a[i];
    return pref;
}
// ---------- Suffix sum ----------
// sum of range [l, r] = suff[l] - suff[r+1]

vector<ll> suffix_sum(const vector<ll>& a){
    int n = a.size();
    vector<ll> suff(n+1, 0);
    for(int i=n-1;i>=0;i--)
        suff[i] = suff[i+1] + a[i];
    return suff;
}
// ---------- 2D Prefix sum ----------
// Rectangle sum (r1,c1) → (r2,c2):
//sum = p[r2+1][c2+1] - p[r1][c2+1] - p[r2+1][c1] + p[r1][c1];

vector<vector<ll>> prefix2D(const vector<vector<ll>>& a){
    int n=a.size(), m=a[0].size();
    vector<vector<ll>> p(n+1, vector<ll>(m+1,0));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            p[i][j] = a[i-1][j-1] + p[i-1][j] + p[i][j-1] - p[i-1][j-1];
    return p;
}

// ---------- Generic min/max update ----------
template<class T>
bool chmax(T &a, T b){ if(b > a){ a = b; return true; } return false; }
template<class T>
bool chmin(T &a, T b){ if(b < a){ a = b; return true; } return false; }


// -------- __int128 I/O --------
#if defined(__SIZEOF_INT128__)
lll readlll(){
    string s; cin >> s;
    lll x = 0; int i = 0; bool neg = false;
    if(!s.empty() && s[0]=='-') neg = true, i = 1;
    for(; i<(int)s.size(); i++) x = x*10 + (s[i]-'0');
    return neg ? -x : x;
}
void printlll(lll x){
    if(x==0){ cout<<0; return; }
    if(x<0) cout<<'-', x=-x;
    string s;
    while(x){ s.push_back('0'+(int)(x%10)); x/=10; }
    reverse(s.begin(), s.end());
    cout<<s;
}
#endif


// ---------- Fast input macros ----------
#define rv(a) for(auto &x : (a)) cin >> x
#define rm(mat) for(auto &r : (mat)) for(auto &x : (r)) cin >> x


void solve(){
    
}

int main(){
    int t;
    cin >> t;
    while(t--)
    solve();
    return 0;
}
