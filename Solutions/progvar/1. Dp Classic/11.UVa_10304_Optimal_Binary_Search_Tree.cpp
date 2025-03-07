#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

// template<class T1, class T2> ostream &operator<<(ostream &os, const pair<T1,T2> &p){ os << '{' << p.first << ", " << p.second << '}'; return os;}
// template<typename C,typename T = decay_t<decltype(*begin(declval<C>()))>,typename enable_if<!is_same<C,string>::value>::type* = nullptr>
// ostream &operator<<(ostream &os, const C &container){bool first = true; stringstream ss; ss << '[';for(const auto &x : container){ if(!first) ss << ", "; first = false; ss << x;} ss << ']';return os << ss.str();}
// vector<string> split(const string& s, char c){ vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.emplace_back(x); return v;}
// inline void dbg_out(vector<string>::iterator it){ cerr << endl;}template<typename T, typename... Args> inline void dbg_out(vector<string>::iterator it, T a, Args... args){ cerr << "[" << it->substr((*it)[0] == ' ', it->length()) << " = " << a << "] "; dbg_out(++it, args...); }
// inline void READ_OUT(vector<string>::iterator it){}template<typename T, typename... Args> inline void READ_OUT(vector<string>::iterator it, T& a, Args&... args){cin >> a;READ_OUT(++it, args...);}
// #define debugg(...) {cerr << "[Line " << __LINE__ << "] :: "; dbg_out(split(#__VA_ARGS__, ',').begin(), __VA_ARGS__);}
// #define READ(...) READ_OUT(split(#__VA_ARGS__, ',').begin(), __VA_ARGS__);

#define       endl             "\n"
#define       ff               first
#define       ss               second
#define       int              long long
#define       dd               long double
#define       ALL(x)           x.begin(), x.end()
#define       FOR(i, s, e)     for(int i = s; i <= e; i++)
#define       FORR(i, s, e)    for(int i = s; i >= e; i--)
#define       getcurrtime      ((double)clock()/CLOCKS_PER_SEC)
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
template<typename T> using pbds = tree<T, null_type, less<T>, rb_tree_tag ,tree_order_statistics_node_update>; 

const int mod = 1e9 + 7;
const int MOD = 998244353;
const int N   = 300;

int n, a[N], pref[N], dp[N][N];

int sum(int l, int r){
	if(l > r) return 0;
	int res = pref[r];
	if(l - 1 >= 0){
		res -= pref[l - 1];
	}
	return res;
}

int f(int l, int r){
	if(l >= r){
		return 0;		
	}
	if(dp[l][r] != -1) return dp[l][r];
	int ans = 1e18;
	for(int i = l; i <= r; i++){
		int curr = f(l, i - 1) + f(i + 1, r);
		curr += sum(l, i - 1) + sum(i + 1, r);
		ans = min(ans, curr);
	}
	return dp[l][r] = ans;
}

int32_t main(){
    while(cin >> n){
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		pref[0] = a[0];
		for(int i = 1; i < n; i++){
			pref[i] = pref[i - 1] + a[i];
		}
		memset(dp, -1, sizeof dp);
		cout << f(0, n - 1) << endl;
    }
}