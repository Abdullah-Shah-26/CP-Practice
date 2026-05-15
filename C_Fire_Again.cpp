#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// Ordered Set
#define oset tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
// order_of_key(k) : No of Elements < k
// *find_by_order(i) : Value at idx i (0 - based)

// ---------- Type aliases ----------
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pi = pair<int,int>;
using pll = pair<ll,ll>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using vs = vector<string>;
using vb = vector<bool>;
using vpi = vector<pi>;
using vvpi = vector<vector<pi>>;

// ---------- Constants ----------
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;

// ---------- Fast IO ----------
static const auto fastio = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

// ---------- Macros ----------
#define rv(a) for(auto &x:(a)) cin>>x
#define pv(a) do{ for(const auto &x:(a)) cout<<x<<' '; cout<<'\n'; }while(0)
#define rm(mat) for(auto &r:(mat)) for(auto &x:(r)) cin>>x
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define nl do{ cout << '\n'; }while(0)

int n,m,k;
int row[4] = {-1,1,0,0};
int col[4] = {0,0,-1,1};

// ---------- Solve ---------
void solve(){
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  cin >> n >> m >> k;

  vector<vector<bool>> vis(n + 1, vector<bool>(m + 1, 0));
  queue<pi> q;

  int lastR = 1, lastC = 1;

  // BFS MultiSrc
  for(int i = 0; i < k; i++){
    int r, c;
    cin >> r >> c;
    q.push({r, c});
    vis[r][c] = 1;

    // EdgeCase: InCase the forest is full of fire from start
    lastR = r;
    lastC = c;
  }

  while(!q.empty()){
    auto [r,c] = q.front();
    q.pop();

    lastR = r;
    lastC = c;

    for(int k = 0; k < 4; k++){
      int nr = r + row[k];
      int nc = c + col[k];
      
      if(nr >= 1 && nr <= n && nc >= 1 && nc <= m && !vis[nr][nc]){
        vis[nr][nc] = 1;
        q.push({nr, nc}); 
      }
    }
  }

  cout << lastR << " " << lastC << " " << endl;
}

// ---------- Main ----------
int main(){
    // int t; 
    // cin >> t;
    // while(t--)
      solve();
    return 0;
}