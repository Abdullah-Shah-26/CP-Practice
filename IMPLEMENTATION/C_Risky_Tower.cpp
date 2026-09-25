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

bool check(int k, int n, int m, vll &v, vvll &a){
  if(k == m)
    return 1;

  priority_queue<ll, vll, greater<ll>> pq;
  ll d = 0; 

  for(int i = n-1; i >= 0; i--){
    for(int j = 0; j < m; j++){
      pq.push(a[i][j]);
      d += a[i][j];

      if(pq.size() > k){
        d -= pq.top();
        pq.pop();
      }
    }

    if(pq.size() == k && d >= v[i])
      return 1;
  }

  return 0;
}

void solve(){
  int n, m;
  cin >> n >> m;

  vll v(n);
  for(ll &x : v)
    cin >> x;

  vvll a(n, vll(m));

  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      cin >> a[i][j];

  int low = 1, high = m;
  int ans = m;

  while(low <= high){
    int mid = low + (high - low)/2;

    if(check(mid, n, m, v, a)){
      ans = mid;
      high = mid - 1;
    }
    else  
      low = mid + 1;
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