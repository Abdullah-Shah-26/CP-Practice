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

int cntTwos(vi &a, int l, int r){
  int cnt = 0;

  for(int i = l; i <= r; i++){
    if(abs(a[i]) == 2)
      cnt++;
  }

  return cnt;
}

// ---------- Solve ---------
void solve(){
  int n;
  cin >> n;

  vi a(n);
  rv(a);

  // Best ans : 
  // Remove x from front
  // Remove y from back

  int bestFront = n;
  int bestBack = 0;

  // Max |2|'s
  int bestTwos = 0;

  int i = 0;
  while(i < n){

    while(i < n && a[i] == 0) 
      i++;

    if(i >= n)
      break;

    int L = i;

    while(i < n && a[i] != 0)
      i++;

    int R = i - 1;

    // Zero Free Segment
    // seg[L.....R]
    int negCnt = 0;
    int firstNeg = -1, lastNeg = -1;

    for(int j = L; j <= R; j++){
       if(a[j] < 0){
        negCnt++;

        if(firstNeg == -1)
          firstNeg = j;

        lastNeg = j;
      }
    }

    // Case 1 : 
    // Even -ve's : Take Whole seg-> since it becomes +ve
    if(negCnt % 2 == 0){
      int twos = cntTwos(a, L, R);

      if(twos > bestTwos){
        bestTwos = twos;

        bestFront = L;
        bestBack = n - R - 1;
      }
    }

    // Case 2 :
    // Odd -ve's : 
    // Try 
    // Remove pref till first -ve
    // Remove suff till last -ve
    else{

      // Option 1 : 
      // Remove left uptil first -ve
      // Remaining = [firstNeg + 1 .......R]
      {
        int newL = firstNeg + 1;
        int newR = R;

        if(newL <= newR){
          int twos = cntTwos(a, newL, newR);

          if(twos > bestTwos){
            bestTwos = twos;

            bestFront = newL;
            bestBack = n - newR - 1;
          }
        }
      }

      // Option 2 : 
      // Remove right uptil last -ve 
      // Remaining = [L..... lastNeg - 1]
      {
        int newL = L;
        int newR = lastNeg - 1;

        if(newL <= newR){
          int twos = cntTwos(a, newL, newR);

          if(twos > bestTwos){
            bestTwos = twos;

            bestFront = newL;
            bestBack = n - newR - 1;
          }
        }
      }
    }
  }

  cout << bestFront << " " << bestBack << endl;
  return;
}

// ---------- Main ----------
int main(){
  int t; 
  cin >> t;
  while(t--)
    solve();
  return 0;
}