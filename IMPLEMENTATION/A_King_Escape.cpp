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

int row[8] = {0, 0, -1, 1, 1, -1, -1, 1};
int col[8] = {1, -1, 0, 0, 1, -1, 1, -1};  

void solve(){
  int n;
  cin >> n;
  int m = n;

  vvi mat(n + 1, vi(m + 1, 0));

  int qx, qy;
  cin >> qx >> qy;

  mat[qx][qy] = 1; 

  int kx, ky;
  cin >> kx >> ky;

  int dx, dy;
  cin >> dx >> dy;

  // Marking cells restricted by queen
  for(int c = 1; c <= n; c++)
    mat[qx][c] = 1;

  for(int r = 1; r <= n; r++)
    mat[r][qy] = 1;

  for(int r = 1; r <= n; r++){
    for(int c = 1; c <=n; c++){
      if(abs(r - qx) == abs(c - qy)){
        mat[r][c] = 1; 
      }
    }
  }  

  queue<pii> q;

  q.push({kx, ky});
  mat[kx][ky] = 1;

  while(!q.empty()){
    auto [r, c] = q.front();
    q.pop();

    if(r == dx && c == dy){
      YES;
      return;
    }

    for(int k = 0; k < 8; k++){
      int nr = r + row[k];
      int nc = c + col[k];
      
      if(nr > 0 && nr <= n && nc > 0 && nc <= m && mat[nr][nc] != 1){
        mat[nr][nc] = 1; 
        q.push({nr, nc});
      }
    }
  }

  NO;

  return;
}

int main(){

  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}