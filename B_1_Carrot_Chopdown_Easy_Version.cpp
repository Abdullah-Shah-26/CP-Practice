#include <bits/stdc++.h>
using namespace std;

using ll = long long;
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
const int MOD = 1e9 + 7;

static const auto fastio=[](){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}();

#define rv(a) for(auto &x:(a)) cin>>x
#define pv(a) do{for(const auto &x:(a)) cout<<x<<' '; cout<<'\n';}while(0)
#define pf(x) cout<<x<<'\n'
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define pb push_back
#define YES cout<<"YES\n"
#define NO cout<<"NO\n"
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define endl '\n'

/*
==========================



==========================
*/

void solve(){
  ll n, m;
  cin >> n >> m;

  vll freq(m + 1);

  rep(i, 0, n){
    ll x; 
    cin >> x;

    freq[x]++;
  }

  vll suff(m + 2);

  for(ll x = m; x >= 1; x--){
    suff[x] = suff[x + 1] + freq[x];
  }

  ll ans = 0; 

  for(ll x = 1; x <= m; x++){
    ll cur = suff[x];

    if(2 * x <= m){
      cur += freq[2 * x];
    }

    ans = max(ans, cur);
  }

  cout << ans << endl;
}

int main(){

  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}