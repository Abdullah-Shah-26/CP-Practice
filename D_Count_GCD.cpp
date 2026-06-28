#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

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

const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 998244353;

static const auto fastio=[](){
 ios::sync_with_stdio(false);
 cin.tie(nullptr);
 return 0;
}();

#define rv(a) for(auto &x:(a)) cin>>x
#define pv(a) do{for(const auto &x:(a)) cout<<x<<' '; cout<<'\n';}while(0)
#define rm(mat) for(auto &r:(mat)) for(auto &x:(r)) cin>>x
#define pm(mat) do{for(const auto &r:(mat)){for(const auto &x:(r)) cout<<x<<' '; cout<<'\n';}}while(0)
#define pf(x) cout<<x<<'\n'
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define pb push_back
#define eb emplace_back
#define rs resize
#define as assign
#define YES cout<<"YES\n"
#define NO cout<<"NO\n"
#define yno(a) cout<<((a)?"YES\n":"NO\n")
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define endl '\n'

bool valid(vll &a){
  for(int i = 1; i < a.size(); i++){
    if((a[i - 1] % a[i]) != 0)
      return false;
  }
  return true;
}

// Distinct Primes
vll getPrimes(ll x){
  vll primes;
  for(ll p = 2; p * p <= x; p++){
    if(x % p == 0){
      primes.push_back(p);
      while(x % p == 0){
        x /= p;
      }
    }
  }

  // x = 17
  if(x > 1)
    primes.pb(x);

  return primes;
}

ll cntWays(ll limit, ll c){
  vll primes = getPrimes(c);
  ll sz = primes.size();
  ll good = limit;

  for(int mask = 1; mask < (1 << sz); mask++){
    ll prod = 1; 
    int chosen = 0;

    for(int i = 0; i < sz; i++){
      if(mask & (1 << i)){
        if(prod > limit) break;

        prod *= primes[i];
        chosen++;
      }
    }

    ll affected = limit/prod;
    if(chosen % 2 == 1)
      good -= affected;
    else
      good += affected;
  }

  return good;
}

void solve(){
  ll n, m;
  cin >> n >> m;

  vll a(n);
  rv(a);

  if(!valid(a)){
    cout << 0 << endl;
    return;
  }

  ll ans = 1;

  for(int i = 1; i < a.size(); i++){
    
    ll A = a[i - 1];
    
    ll B = a[i];

    // gcd(A,B) = B
    // gcd(A,bx) = B
    // only possible if A/B == 0
    // 1 <= x <= m
    // x <= m/B

    // m/B == 0 then there is no valid x
    if(B > m){
      pf(0);
      return;
    }

    ll limit = m/B;
   
    ll c = A/B;
   
    ll ways = cntWays(limit, c);
   
    ans = ans * ways % MOD;
  }

  pf(ans);
}

int main(){
 int t;
 cin>>t;
 while(t--) solve();
 return 0;
}