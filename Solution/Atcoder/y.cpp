/**
 * author: abhishek soni ..... [NSIT'22]
 * created: 10/06/2021  09:49:46
 */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template<class T1, class T2> ostream &operator<<(ostream &os, const pair<T1,T2> &p){ os << '{' << p.first << ", " << p.second << '}'; return os;}
template<typename C,typename T = decay_t<decltype(*begin(declval<C>()))>,typename enable_if<!is_same<C,string>::value>::type* = nullptr>
ostream &operator<<(ostream &os, const C &container){bool first = true; stringstream ss; ss << '[';for(const auto &x : container){ if(!first) ss << ", "; first = false; ss << x;} ss << ']';return os << ss.str();}
vector<string> split(const string& s, char c){ vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.emplace_back(x); return v;}
inline void dbg_out(vector<string>::iterator it){ cerr << endl;}template<typename T, typename... Args> inline void dbg_out(vector<string>::iterator it, T a, Args... args){ cerr << "[" << it->substr((*it)[0] == ' ', it->length()) << " = " << a << "] "; dbg_out(++it, args...); }
inline void READ_OUT(vector<string>::iterator it){}template<typename T, typename... Args> inline void READ_OUT(vector<string>::iterator it, T& a, Args&... args){cin >> a;READ_OUT(++it, args...);}
template<typename T> inline void debugg2D(T a, int n, int m){for(int i = 0; i < n; i++){for(int j = 0; j < m; j++){cout << a[i][j] << " ";}cout << endl;}}
#define debugg(...) {cerr << "[Line " << __LINE__ << "] :: "; dbg_out(split(#__VA_ARGS__, ',').begin(), __VA_ARGS__);}
#define READ(...) READ_OUT(split(#__VA_ARGS__, ',').begin(), __VA_ARGS__);

#define endl             "\n"
#define ff               first
#define ss               second
#define vt               vector
#define ar               array
#define int              long long
#define dd               long double
#define ALL(x)           x.begin(), x.end()
#define FOR(i, s, e)     for(int i = s; i <= e; i++)
#define FORR(i, s, e)    for(int i = s; i >= e; i--)
#define getcurrtime      ((double)clock()/CLOCKS_PER_SEC)
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
template<typename T> using pbds = tree<T, null_type, less<T>, rb_tree_tag ,tree_order_statistics_node_update>; 

const int mod = 1e9 + 7;
const int MOD = 998244353;
const int N   = 5e5 + 5;


int fact[N] , inv[N];

int pow(int a, int b, int m){
    if(a == 0) return 0;
    a %= m;
    int res = 1ll;
    while(b){
        if(b&1) res = (res * a) % mod;
        b >>= 1ll;
        a = (a * a) % mod;
    }
    return res;
}

void pre(){
    fact[0] = inv[0] = 1; 
    for(int i = 1;  i < N ; i++){
        fact[i] = (fact[i - 1] * i) % mod;
        inv[i] = pow(fact[i] , mod - 2 , mod);
    }
}

int ncr(int n , int r){
    if(n < 0 || r < 0 || r > n) return 0;
    int ans = fact[n];
    ans = (ans * inv[n - r]) % mod;
    ans = (ans * inv[r]) % mod;
    return ans;
}


int f(int a, int b){
    return ncr(a + b, b);
}

void test_cases(){
    int h, w, n; cin >> h >> w >> n;
    vector<array<int, 2>> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i][0] >> a[i][1];
    }
    sort(ALL(a), [&](auto &a, auto &b){
        return a[0] + a[1] < b[0] + b[1];
    });

    a.push_back({h, w});
    vector<int> dp(n + 1, 0);
    for(int i = 0; i <= n; i++){
        dp[i] = f(a[i][0] - 1, a[i][1] - 1);
        for(int j = 0; j < i; j++){
            if(a[i][0] >= a[j][0] && a[i][1] >= a[j][1]){
                int mid = (dp[j] * f(a[i][0] - a[j][0], a[i][1] - a[j][1]))%mod;
                dp[i] = (dp[i] - mid  + mod)%mod;
            }            
        }
    }
    cout << dp[n] << endl;
}


int32_t main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int tt = 1;
    // cin >> tt;
    pre();
    for(int T = 1; T <= tt; T++){
        // cerr << endl << "Case #" << T << ": " << endl;
        test_cases();
    }
}


