#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template<class T1, class T2> ostream &operator<<(ostream &os, const pair<T1,T2> &p){ os << '{' << p.first << ", " << p.second << '}'; return os;}
template<typename C,typename T = decay_t<decltype(*begin(declval<C>()))>,typename enable_if<!is_same<C,string>::value>::type* = nullptr>
ostream &operator<<(ostream &os, const C &container){bool first = true; stringstream ss; ss << '[';for(const auto &x : container){ if(!first) ss << ", "; first = false; ss << x;} ss << ']';return os << ss.str();}
vector<string> split(const string& s, char c){ vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.emplace_back(x); return v;}
inline void dbg_out(vector<string>::iterator it){ cerr << endl; }
template<typename T, typename... Args> inline void dbg_out(vector<string>::iterator it, T a, Args... args){ cerr << "[" << it->substr((*it)[0] == ' ', it->length()) << " = " << a << "] "; dbg_out(++it, args...); }
#define debugg(...) {cerr << "[Line " << __LINE__ << "] :: "; dbg_out(split(#__VA_ARGS__, ',').begin(), __VA_ARGS__);}

#define endl             "\n"
#define ff               first
#define ss               second
#define int              long long
#define dd               long double
#define pb               push_back
#define ALL(x)           x.begin(), x.end()
#define FOR(i, s, e)     for(int i = s; i <= e; i++)
#define FORR(i, s, e)    for(int i = s; i >= e; i--)
typedef pair<int, int>   pii;
typedef pair<int, pii>   piii;

template<typename T> using pbds = tree<T, null_type, less<T>, 
rb_tree_tag ,tree_order_statistics_node_update>; 

const int MOD = 998244353;
const int N   = 5e5 + 5;

int n, mod;
vector<vector<int>> adj;
vector<int> dp, ans;

void dfs(int u, int p = -1){
    dp[u] = 1;
    for(int v : adj[u]){
        if(v == p) continue;
        dfs(v, u);
        dp[u] *= (dp[v] + 1);
        dp[u] %= mod;
    }
}

void reroot(int u, int p, int res){
    ans[u] = (res * dp[u])%mod;
    vector<int> child;
    for(int v : adj[u]){
        if(v == p) continue;
        child.push_back(v);
    }
    int nn = child.size();
    vector<int> pref(nn + 1, 1), suff(nn + 1, 1);
    for(int i = 1; i <= nn; i++){
        pref[i] = (pref[i - 1] * (dp[child[i - 1]] + 1))%mod;
    }
    for(int i = nn - 1; i >= 0; i--){
        suff[i] = (suff[i + 1] * (dp[child[i]] + 1))%mod;
    }
    for(int i = 0; i < nn; i++){
        int v = child[i];
        reroot(v, u, (1 + (res * pref[i]%mod * suff[i + 1])%mod)%mod);
    }
}

void test_cases(){
    cin >> n >> mod;
    adj = vector<vector<int>>(n, vector<int>());
    dp = vector<int>(n, 0);
    ans = vector<int>(n, 1);
    for(int i = 0; i < n - 1; i++){
        int s, d; cin >> s >> d;
        adj[s - 1].push_back(d - 1);
        adj[d - 1].push_back(s - 1);
    }
    dfs(0);
    reroot(0, -1, 1);
    for(int i = 0; i < n; i++){
        cout << ans[i]%mod << endl;
    }
}


int32_t main(){
    // ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int tt = 1;
    // cin >> tt;
    for(int T = 1; T <= tt; T++){
        // cerr << endl << "Case #" << T << ": " << endl;
        test_cases();
    }
}