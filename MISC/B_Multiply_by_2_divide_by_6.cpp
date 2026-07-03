#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	long long t;
	cin >> t; // Read the number of test cases
	while (t--)
	{
		ll n;
    cin >> n;

    ll cnt3 = 0;
    ll cnt2 = 0;

    while(n > 0 && n % 3 == 0) {
      cnt3++;
      n/=3;
    }

    while(n > 0 && n % 2 == 0){
      cnt2++;
      n/=2;
    }


    if(n > 1 || cnt2 > cnt3)
      cout << -1 << endl;
    else 
      cout <<(cnt3 - cnt2) + cnt3 << endl;
	}
	return 0;
}

// Time Complexity (TC): O(log2(n)) = O(30)
// Space Complexity (SC): O(1)
