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

  0 1 2 3 4 5
  2 3 6 9 5 7
  3 2 7 10 6 10



==========================
*/

void solve(){
  int n;
  cin >> n;

  vll a(n), b(n);

  rv(a);
  rv(b);


  vll neg, pos;

  for(int i = 0; i < n; i++){
    ll d = b[i] - a[i];

    if(d < 0)
      neg.pb(d);
    else  
      pos.pb(d);
  }

  sort(all(neg));
  sort(all(pos));

  int ans = 0;

  int i = 0, j = pos.size() - 1;

  while(i < neg.size() && j >= 0){
    if(neg[i] + pos[j] >= 0){
      ans++;
      i++;
      j--;
    }
    else{
      i++;
    }
  }

  int remPos = j + 1; 
  ans += remPos/2;

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