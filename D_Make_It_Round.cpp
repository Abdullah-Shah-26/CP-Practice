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

// pow of 2 & 5
ll p2[19];
ll p5[19];

void solve(){
  int n, m;
  cin >> n >> m;

  int c2 = 0, c5 = 0; 

  int temp = n;
  while(temp % 2 == 0){
    temp /= 2;
    c2++;
  }

  temp = n;
  while(temp % 5 == 0){
    temp /= 5; 
    c5++;
  }

  for(int d = 18; d >= 0; d--){
    
    // Need these many more no of 2s & 5s for d no of trailing zeros
    int e2 = max(0, d - c2);
    int e5 = max(0, d - c5);
  
    ll need = p2[e2] * p5[e5];

    if(need <= m){
      int maxK = m - m % need;
      cout << 1LL * maxK * n << endl;
      return;
    }
  }
}

int main(){
  p2[0] = 1;
  p5[0] = 1;

  for(int i = 1; i < 19; i++){
    p2[i] = 2 * p2[i - 1];
    p5[i] = 5 * p5[i - 1];
  }


  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}