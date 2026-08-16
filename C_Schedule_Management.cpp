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

n workers
m tasks

Assign each task - a worker

Proficient worker - 1hr 
else - 2hr 

Workers work in parallel
Each can work only on 1 task at once

All tasks must be completed as early as possible 

worker = i

Can finish atmost T of their own task
cause each takes 1 hr

If they have more than T tasks

If(cnt[i] > T)
  extra = cnt[i] - T

Task must be given to other workers 

If(cnt[i] < T)
  freeTime = T - cnt[i]

A task they aren't proficient takes 2 hours f
So they can do (T - cnt[i])/2 other tasks

==========================
*/

bool can(ll T, vll &cnt){
  // need = tasks that need another worker
  // extra = foreign tasks spare workers can handle

  ll need = 0, extra = 0; 

  for(int i = 1; i < cnt.size(); i++){
    if(cnt[i] > T){
      need += cnt[i] - T;
    }
    else if(cnt[i] < T){
      extra += (T - cnt[i])/2;
    }
  }

  return extra >= need;
}

void solve(){
  ll n, m;
  cin >> n >> m;

  vll a(m);
  rv(a);

  vll cnt(n + 1, 0); // cnt[i] = no of tasks worker i is proficient

  for(int i = 0; i < m; i++){
    cnt[a[i]]++;
  }

  ll low = 1, high = 2 * m;
  ll ans = 2 * m;

  while(low <= high){
    ll mid = low + (high - low)/2;

    if(can(mid, cnt)){
      ans = mid; 
      high = mid - 1; 
    }
    else{
      low = mid + 1; 
    }
  }

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