#include <bits/stdc++.h>
using namespace std;

// ---------- Type aliases ----------
using ll = long long;
using ull = unsigned long long;

#if defined(__SIZEOF_INT128__)
using lll = __int128;
using ulll = unsigned __int128;
#endif

using ld = long double;

using pi = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using vs = vector<string>;
using vb = vector<bool>;
using vpi = vector<pi>;
using vvpi = vector<vector<pi>>;

// ---------- Constants ----------
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;

// ---------- Fast IO ----------
static const auto fastio = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();



// ---------- Macros ----------
#define rv(a)           \
    for (auto &x : (a)) \
    cin >> x
#define rm(mat)             \
    for (auto &r : (mat))   \
        for (auto &x : (r)) \
    cin >> x
#define pb push_back
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define per(i, a, b) for (int i = (b) - 1; i >= (a); --i)

// ---------- Solve ----------
void solve()
{
    string s;
    cin >> s;
    ll pos;
    cin >> pos;

    ll n = s.size();
    
    string st; // string used as stack

    for(char &c : s){
        // Remove one char and move to next smaller string
        while(!st.empty() && st.back() > c && pos > n){
            st.pop_back();
            pos -= n;
            n--;
        }
        st.pb(c);
    }


    // Handle Edge Case : Non Decreasing String //  abcd
    while(pos > n){
        st.pop_back();
        pos -= n;
        n--;
    }
    cout << st[pos - 1] ;
    return;
}

// ---------- Main ----------
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}