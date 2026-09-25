#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
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

static const auto fastio = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}();

#define rv(a) \
  for (auto& x : (a)) cin >> x
#define pv(a)                                   \
  do {                                          \
    for (const auto& x : (a)) cout << x << ' '; \
    cout << '\n';                               \
  } while (0)
#define pf(x) cout << x << '\n'
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define pb push_back
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define endl '\n'

/*
==========================



==========================
*/

void solve() {
  int n;
  cin >> n;

  string s;
  cin >> s;

  int cnt[26] = {0};

  for (int i = 0; i < n; i++) cnt[s[i] - 'a']++;

  for (int i = 0; i < 26; i++) {
    if (cnt[i] == 0) {
      cout << (char)(i + 'a') << endl;
      return;
    }
  }

  set<string> st;

  for (int i = 0; i < n - 1; i++) {
    string temp = "";
    temp += s[i];
    temp += s[i + 1];
    st.insert(temp);
  }

  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < 26; j++) {
      string temp = "";
      temp += (char)(i + 'a');
      temp += (char)(j + 'a');

      if (st.find(temp) == st.end()) {
        cout << temp << "\n";
        return;
      }
    }
  }

  st.clear();

  for (int i = 0; i < n - 2; i++) {
    string temp = "";
    temp += s[i];
    temp += s[i + 1];
    temp += s[i + 2];
    st.insert(temp);
  }

  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < 26; j++) {
      for (int k = 0; k < 26; k++) {
        string temp;
        temp += char(i + 'a');
        temp += char(j + 'a');
        temp += char(k + 'a');

        if (st.find(temp) == st.end()) {
          cout << temp << '\n';
          return;
        }
      }
    }
  }

  return;
}

int main() {
  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}