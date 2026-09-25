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
  ll n, m;
  cin >> n >> m;

  vll a(n);
  rv(a);

  vll cnt(m);

  for(int i = 0; i < n; i++){
    int r = a[i] % m;
    cnt[r]++;
  }
using ll = long long;

class Solution {
public:
  vector<long long> distance(vector<int>& nums) {
    int n = nums.size();
  
    unordered_map<ll, vector<int>> mp;

    vector<ll> ans(n, 0);

    for(int i = 0; i < n; i++)
      mp[nums[i]].push_back(i);    
  
    for(auto &[value, pos] : mp){
      int m = pos.size();

      vector<ll> pref(m);

      pref[0] = pos[0];

      for(int i = 1; i < m; i++)
        pref[i] = pref[i - 1] + pos[i];

      ll totalSum = pref[m - 1];

      for(int i = 0; i < m; i++){
        int idx = pos[i];

        ll leftCnt = i;
        ll leftSum = (i > 0 ? pref[i - 1] : 0);

        ll rightCnt = m - i - 1;
        ll rightSum = totalSum - pref[i];

        ll left = leftCnt * idx - leftSum;
        ll right = rightSum - rightCnt * idx;

        ans[idx] = left + right;
      }
    }

    return ans;
  }
};
  ll ans = 0;

  for(int i = 0; i < m; i++){
    int x = cnt[i];
    int y = cnt[(m - i) % m];

    if(x == 0 && y == 0)
      continue;

    int temp = min(x, y);

    x -= min(temp + 1, x);
    y -= min(temp + 1, y);

    ans++;

    ans += (x + y);

    cnt[i] = 0;
    cnt[(m - i) % m] = 0; 
  }

  cout << ans << "\n";
}

int main(){

  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}