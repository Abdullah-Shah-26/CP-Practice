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
const ll LINF = 4e18;
const int MOD = 1e9 + 7;

static const auto fastio = [](){
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
#define YES cout<<"Yes\n"
#define NO cout<<"No\n"
#define yno(a) cout<<((a)?"Yes\n":"No\n")
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define endl '\n'

/*
==========================



==========================
*/

void solve(){
  int n;
  cin >> n;

  vll a(n);
  rv(a);

  ll top[3] = {-1, -1, -1};

  for(int i = 0; i < n; i++){
    ll x = a[i];
    
    if(x >= top[0]){
      top[2] = top[1];
      top[1] = top[0];
      top[0] = x;
    }
    else if(x >= top[1]){
      top[2] = top[1];
      top[1] = x;
    }
    else if(x >= top[2]){
      top[2] = x;
    }

    if(i >= 2)
      cout << top[2] << endl;
  }
}

int main(){
  int t = 1;
  // cin >> t;

  while (t--) {
    solve();
  }
  return 0;
}