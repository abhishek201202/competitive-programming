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
const int N   = 5e5 + 5;



int32_t main(){
    // freopen("input.txt", "r", stdin);

	auto LCS = [&](vector<int> &a, vector<int> &b){
		int n = a.size();
		int m = b.size();
		int dp[n + 1][m + 1] = {};
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				if(a[i - 1] == b[j - 1]){
					dp[i][j] = dp[i - 1][j - 1] + 1;
				}else{
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				}				
			}
		}
		return dp[n][m];
	};

	int n; cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		int x; cin >> x;
		a[x - 1] = i;
	}
	vector<int> b(n);
	int x;
	while(cin >> x){
		b[x - 1] = 0;
		for(int i = 1; i < n; i++){
			int x; cin >> x;
			b[x - 1] = i;
		}
		cout << LCS(a, b) << endl;
	}

}