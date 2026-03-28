#include<bits/stdc++.h>
using namespace std;

int n,d;
vector<int>a;

bool check(double x, int &L,int &R){
  vector<double> pref(n + 1, 0);

  for(int i = 1; i <= n; i++){
    pref[i] = pref[i-1] + (a[i-1] - x);
  }

  double minPref = 0;
  int minIdx = 0;

  for(int r = d; r <= n; r++){
    // Allowed prefixed upto r - d

    if(pref[r-d] < minPref){
      minPref = pref[r - d];
      minIdx = r - d;
    }


    if(pref[r] - minPref >= 0){
      L = minIdx + 1;
      R = r;
      return 1;
    }
  }
  return 0;
}

int main(){
  cin >> n >> d;
  a.resize(n);

  for(int i = 0; i < n; i++) cin >> a[i];

  double l = 0, r = 100.0;
  int resL = -1, resR = -1;

  int it = 60;
  
  while(it--){
    double mid = (l + r)/2;

    int L,R;

    if(check(mid, L, R)){
      l = mid;
      resL = L;
      resR = R;

    } else {
      r = mid;
    }
  }

  cout << resL << " " << resR << "\n";
}