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

static const auto fastio=[](){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}();

#define rv(a) for(auto &x:(a)) cin>>x
#define pv(a) do{for(const auto &x:(a)) cout<<x<<' '; cout<<'\n';}while(0)
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
  int u, v;
  cin >> u >> v;

  // Directed edge can be from u to (u + v)
  // If v itself is less than u, its not possible 

  bool ok = (u <= v);
  int cnt = 0; 

  // u can have more than or equal set bits compared to v

  for(int i = 0; i < 30; i++){
    if((u >> i) & 1) cnt++;
    if((v >> i) & 1) cnt--;

    // At any point u can have >= set bits in v
    // If at any pt u has less set bits than v
    // We cannot make u to v 
    if(cnt < 0)
      ok = false;
  }

  if(ok) YES;
  else NO;
}

int main(){

  int t;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}