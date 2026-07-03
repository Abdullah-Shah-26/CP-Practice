#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  string s;
  cin >> s;

  int plusCnt = count(s.begin(), s.end(), '+');
  int minusCnt = n - plusCnt;

  int q;
  cin >> q;

  while(q--){
    int a,b;
    cin >> a >> b;

    if(plusCnt == minusCnt){
      cout << "YES\n";
      continue;
    }

    if(plusCnt != minusCnt && a == b){
      cout << "NO\n";
      continue;
    }

    int g = gcd(a,b);
    int x = b/g;
    int y = a/g;

    int diff = abs(plusCnt - minusCnt);
    int step = abs(x - y);

    // diff - step, diff - 2 * step, diff - 3 * step ... until we get 0

    if(diff % step != 0){
      cout << "NO\n";
      continue;
    }

    int jumps = diff/step;

    int total = (x + y) * jumps;
  
    if(total <= n){
      cout << "YES\n";
    }
    else{
      cout << "NO\n";
    }
  }
}