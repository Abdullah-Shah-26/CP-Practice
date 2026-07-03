#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

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

const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;

static const auto fastio = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

#define rv(a) for(auto &x:(a)) cin>>x
#define pv(a) do{for(const auto &x:(a)) cout<<x<<' '; cout<<'\n';}while(0)
#define rm(mat) for(auto &r:(mat)) for(auto &x:(r)) cin>>x
#define pm(mat) do{for(const auto &r:(mat)){for(const auto &x:(r)) cout<<x<<' '; cout<<'\n';}}while(0)
#define pf(x) cout<<x<<'\n'
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define pb push_back
#define eb emplace_back
#define rs resize
#define as assign
#define YES cout<<"YES\n"
#define NO cout<<"NO\n"
#define yno(a) cout<<((a)?"YES\n":"NO\n")
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define endl '\n'

void solve(){
  int n, m, y;
  cin >> n >> m >> y;

  vvpii adj(n + 1);

  for(int i = 0; i < m; i++){
    int u, v, t;
    cin >> u >> v >> t;

    u--, v--;

    adj[u].pb({v, t});
    adj[v].pb({u, t});
  }

  vi v(n);
  rv(v);

  for(int i = 0; i < n; i++){
    adj[i].pb({n, y + v[i]});
    adj[n].pb({i, v[i]});
  }

  priority_queue<pii, vpii, greater<pii>> pq;
  vi dist(n+1, INF);

  pq.push({0, 0});

  dist[0] = 0;

  while(!pq.empty()){
    auto [d, cur] = pq.top();
    pq.pop();

    if(dist[cur] != d) continue;

    for(auto &[nei, edWt] : adj[cur]){
      if(dist[nei] > d + edWt){
        dist[nei] = d + edWt;
        pq.push({dist[nei], nei});
      }
    }
  }

  for(int i = 1; i <= n; i++) 
    cout << dist[i] << " ";
}

int main(){
   solve();
 return 0;
}