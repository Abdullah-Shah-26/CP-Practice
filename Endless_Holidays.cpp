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
using pi = pair<int,int>;
using pll = pair<ll,ll>;
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
static const auto fastio = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

// ---------- Modular arithmetic ----------
ll modPow(ll a,ll b,ll m=MOD){
    ll res=1;
    while(b){
        if(b&1) res=res*a%m;
        a=a*a%m;
        b>>=1;
    }
    return res;
}
ll modInv(ll a,ll m=MOD){ return modPow(a,m-2,m); }

// ---------- Bit helpers ----------
int bitCount(ll x){ return __builtin_popcountll(x); }
int msbIndex(ll x){ return 63-__builtin_clzll(x); }
int lsbIndex(ll x){ return __builtin_ctzll(x); }

// ---------- Divisors ----------
vector<ll> getDivisors(ll n){
    vector<ll> d;
    for(ll i=1;i*i<=n;i++){
        if(n%i==0){
            d.push_back(i);
            if(i*i!=n) d.push_back(n/i);
        }
    }
    sort(d.begin(), d.end());
    return d;
}

// ---------- Primes (Sieve) ----------
// Usage: vector<int> spf; auto primes = linearSieve(N, spf);
// spf[x] = smallest prime factor of x (for x>=2)
vector<int> linearSieve(int n, vector<int>& spf){
    spf.assign(n+1, 0);
    vector<int> primes;
    for(int i=2;i<=n;i++){
        if(spf[i]==0){ spf[i]=i; primes.push_back(i); }
        for(int p: primes){
            if(p>spf[i] || 1LL*i*p>n) break;
            spf[i*p]=p;
        }
    }
    return primes;
}
bool isPrimeSieve(int x, const vector<int>& spf){
    return x>=2 && x<(int)spf.size() && spf[x]==x;
}

// ---------- Primality (sqrt) ----------
bool isPrime(ll n){
    if(n<2) return false;
    for(ll i=2;i*i<=n;i++) if(n%i==0) return false;
    return true;
}

// ---------- Macros ----------
#define rv(a) for(auto &x:(a)) cin>>x
#define pv(a) do{ for(const auto &x:(a)) cout<<x<<' '; cout<<'\n'; }while(0)
#define rm(mat) for(auto &r:(mat)) for(auto &x:(r)) cin>>x
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define nl do{ cout << '\n'; }while(0)

int n,m,w;

int node(int city, int day){
  return city * w + day;
}

// ---------- Solve ---------

void solve() {
    cin >> n >> m >> w;

    vvi roads(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        roads[u].pb(v);
        roads[v].pb(u);
    }

    vector<string> s(n);
    rv(s);

    int V = n * w;

    vvi adj(V), radj(V);

    for (int u = 0; u < n; u++) {
        for (int day = 0; day < w; day++) {
            if (s[u][day] == 'x') continue;

            int nextDay = (day + 1) % w;
            int from = node(u, day);

            auto addEdge = [&](int v) {
                if (s[v][nextDay] == 'o') {
                    int to = node(v, nextDay);
                    adj[from].pb(to);
                    radj[to].pb(from);
                }
            };

            addEdge(u);                 // stay
            for (int v : roads[u]) addEdge(v);
        }
    }

    // reachable from valid starts
    vi vis(V, 0);
    queue<int> q;

    for (int u = 0; u < n; u++) {
        if (s[u][0] == 'o') {
            int st = node(u, 0);
            vis[st] = 1;
            q.push(st);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (!vis[v]) {
                vis[v] = 1;
                q.push(v);
            }
        }
    }

    // Kosaraju pass 1
    vi used(V, 0), order;

    function<void(int)> dfs1 = [&](int u) {
        used[u] = 1;
        for (int v : adj[u])
            if (vis[v] && !used[v]) dfs1(v);
        order.pb(u);
    };

    for (int u = 0; u < V; u++)
        if (vis[u] && !used[u]) dfs1(u);

    reverse(all(order));

    // pass 2
    vi comp(V, -1), sz;

    function<void(int,int)> dfs2 = [&](int u, int id) {
        comp[u] = id;
        sz[id]++;

        for (int v : radj[u])
            if (vis[v] && comp[v] == -1)
                dfs2(v, id);
    };

    int cc = 0;

    for (int u : order) {
        if (comp[u] == -1) {
            sz.pb(0);
            dfs2(u, cc++);
        }
    }

    bool ok = false;

    // SCC size > 1 => cycle
    for (int id = 0; id < cc; id++)
        if (sz[id] > 1) ok = true;

    // singleton self-loop
    for (int u = 0; u < V && !ok; u++) {
        if (!vis[u]) continue;
        if (sz[comp[u]] != 1) continue;

        for (int v : adj[u])
            if (u == v) ok = true;
    }

    cout << (ok ? "Yes\n" : "No\n");
}


// ---------- Main ----------
int main(){
    int t; 
    cin >> t;
    while(t--)
      solve();
    return 0;
}