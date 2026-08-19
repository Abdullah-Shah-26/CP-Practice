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
  ll n;
  cin >> n;
  
  vll u(n), s(n);
  rv(u);
  rv(s);

  // Grouped skills by universities
  // [u1] -> {x, y, z}
  // [u2] -> {p, q, r}

  vvi uni(n + 1);

  for(int i = 0; i < n; i++)
    uni[u[i]].push_back(s[i]);

  for(int i = 1; i <= n; i++){
    sort(rall(uni[i]));
  }

  vll ans(n + 1, 0);

  for(int i = 1; i <= n; i++){
    if(uni[i].empty())
      continue;

    int m = uni[i].size();

    vll pref(m + 1, 0);

    for(int j = 1; j <= m; j++)
      pref[j] = pref[j - 1] + uni[i][j - 1];

    // Trying every team of size k upto m
    for(int k = 1; k <= m; k++){
      int take = (m/k) * k; // These are the no of guys I can take 
      
      ans[k] += pref[take];
    }
  }

  for(int i = 1; i <= n; i++)
    cout << ans[i] << ' ';

  cout << endl;
}

int main(){

  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}