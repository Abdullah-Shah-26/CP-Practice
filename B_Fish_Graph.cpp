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
#define pm(mat) do{ for(const auto &r:(mat)){ for(const auto &x:(r)) cout<<x<<' '; cout<<'\n'; } }while(0)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define pb push_back
#define eb emplace_back
#define rs resize
#define as assign
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define yno(a) cout << ((a) ? "YES\n" : "NO\n")
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define endl '\n'

int n, m;
vvi adj;

// ---------- Solve ---------
void solve(){
  cin >> n >> m;
  adj.assign(n + 1, {});

  for(int i = 0; i < m; i++){
    int u,v;
    cin >> u >> v;

    adj[u].pb(v);
    adj[v].pb(u);
  }

  for(int u = 1; u <= n; u++){

    if(adj[u].size() < 4)
      continue;

    // Special Node 
    // Deg >= 4
    // Mark its neighbours

    vi isNbr(n + 1);
    for(int v : adj[u]){
      isNbr[v] = 1;
    }
    
    // DFS from each nei of u, trying to reach another nei
    for(int st : adj[u]){

      int end = -1;
      vi parent(n + 1, -1);
      vb vis(n + 1, 0);

      function<bool(int)> dfs = [&](int node){
        vis[node] = 1;

        for(int nxt : adj[node]){
          if(vis[nxt])
            continue;

          if(nxt == u)
            continue;

          parent[nxt] = node;

          if(st != nxt && isNbr[nxt]) {// nxt is nei of u & got visitied by node without u, i.e cycle exist
            end = nxt;
            return true;
          }

          if(dfs(nxt))
            return true;
        }
        
        return false;
      };

      if(!dfs(st)) // It is nei of u, but not a part of cycle
        continue;

      vi path;
      int cur = end;

      while(cur != -1){
        path.pb(cur);
        
        if(cur == st)
          break;
        
        cur = parent[cur];
      }

      reverse(rall(path));

      vb inCycle(n + 1, false);

      inCycle[u] = true;
      for(int x : path)
        inCycle[x] = true;
    
      vi tails;
      
      for(int v : adj[u]){
        if(!inCycle[v])
          tails.pb(v);

        if(tails.size() == 2)
          break;
      }

      if(tails.size() < 2)
        continue;

      vpii ans;

      ans.pb({u, path[0]});

      for(int i = 0; i < path.size() - 1; i++)
        ans.pb({path[i], path[i + 1]});

      ans.pb({u, end});
      ans.pb({u, tails[0]});
      ans.pb({u, tails[1]});

      YES;
      cout << ans.size() << endl;

      for(auto [a,b] : ans)
        cout << a << " " << b << endl;
      
      return;
    }
  }

  NO;
}

// ---------- Main ----------
int main(){
  int t; 
  cin >> t;
  while(t--)
    solve();
  return 0;
}