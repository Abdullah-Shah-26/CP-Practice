#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

bool check(int n){
  string s = to_string(n);
  string str = s;
  reverse(s.begin(), s.end());
  return s==str;
}

const int M = 1e9 + 7;
const int N = 4e4 + 1; 

int main(){
  fastio();

  // Push all palindromic no's upto N
  vector<int> a;
  for(int i = 1; i < N; i++){
    if(check(i)){
      a.push_back(i);
    }
  }

  int sz = a.size();

  vector<int> dp(N,0);
  dp[0] = 1; 

  for(int i = 0; i < sz; i++){
    for(int x = 1; x < N; x++){
      if(x - a[i] >= 0){
        dp[x] = (dp[x] + dp[x-a[i]])%M;
      }
    }
  }

  int t;
  cin >> t;

  while(t--){
    int n;
    cin>> n;

    cout << dp[n] << endl;
  }
}