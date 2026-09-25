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

vi find(vi &arr){
  vpii temp(arr.size());

  rep(i,0,arr.size()){
    temp[i].first = arr[i];
    temp[i].second = i; 
  }

  sort(all(temp), greater<pii>());

  vi ans(3);

  for(int i = 0; i < 3; i++)
    ans[i] = temp[i].second; // Top 3 indices whose elements have max value 

  return ans;
}

void solve(){
  int n;
  cin >> n;

  vi a(n), b(n), c(n);
  rv(a);
  rv(b);
  rv(c);

  vi maxa = find(a);
  vi maxb = find(b);
  vi maxc = find(c);

  int ans = 0; 

  rep(i,0,3){
    rep(j,0,3){
      rep(k,0,3){

        // Indices 
        int x = maxa[i], y = maxb[j], z = maxc[k];

        if((x == y) || (x == z) || (y == z))
          continue;

        ans = max(ans, a[x] + b[y] + c[z]);
      }
    }
  }

  pf(ans);
}

int main(){

  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}