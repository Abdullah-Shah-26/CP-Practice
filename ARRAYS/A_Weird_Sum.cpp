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

(r1,c1) & (r2,c2)

Length of shortest path b/w cells 
where each consecutive cells in path must have common side

Sigma (r1 - r2) + Sigma (c1 - c2)

x1 <= x2 <= x3

v = [1,2,4,5]

i = 3
v[i] = 5

prev elements : 1, 2, 4

want : |5 - 1| + |5 - 2| + |5 - 4|
     : (3 * 5) - (1 + 2 + 4)
     : 15 - 7
     : 8

==========================
*/

ll calc(vi &v){
  sort(all(v));

  ll ans = 0; 
  ll sum = 0; 

  for(int i = 0; i < v.size(); i++){
    ll prev = i; 
    ans += 1LL * prev * v[i] - sum;
    sum += v[i];
  }

  return ans;
}

void solve(){
  int n, m;
  cin >> n >> m;

  map<int, vector<int>> rows, cols; 

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      int x; 
      cin >> x;

      rows[x].push_back(i);
      cols[x].push_back(j);
    }
  }

  ll ans = 0; 

  for(auto &[color, v] : rows)
    ans += calc(v);

  for(auto &[color, v] : cols)
    ans += calc(v);

  cout << ans << endl;
}

int main(){

  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}