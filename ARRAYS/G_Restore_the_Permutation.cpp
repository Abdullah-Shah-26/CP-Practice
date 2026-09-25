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
  int n;
  cin >> n;

  vi p(n + 1);
  vi pos(n + 1);

  for(int i = 2; i <= n; i += 2){
    cin >> p[i];
    pos[p[i]] = i - 1; 
  }

  priority_queue<int> pq;

  // X = current no we are trying to put in perm
  for(int x = n; x >= 1; x--){
    if(pos[x]) // Already present in b
      pq.push(pos[x]);
    else{ // Not present in b, need placement in p, place it at 
      if(pq.empty()){
        cout << -1 << endl;
        return;
      }
      
      // Max unassigned idx
      int idx = pq.top();
      pq.pop();

      p[idx] = x;
    }
  }

  for(int i = 1; i <= n; i++)
    cout << p[i] << " ";

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