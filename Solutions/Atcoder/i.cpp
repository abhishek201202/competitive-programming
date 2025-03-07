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

const int mod = 1e9 + 7;
const int MOD = 998244353;
const int N   = 5e5 + 5;


// HHHHTT
// HHHHHT


void test_cases(){
    int n; cin >> n;
    vector<dd> a(n);
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    }
    int B = (n - 1) / 2;
    dd dp[n + 1][B + 1][2];
    memset(dp, 0, sizeof dp);
	dp[1][0][1] = a[0];
	if(B > 0){
		dp[1][1][0] = 1.0 - a[0];
	}
    for(int i = 2; i <= n; i++){
    	for(int j = 0; j <= B; j++){
			dp[i][j][1] = (dp[i - 1][j][0] + dp[i - 1][j][1]) * a[i - 1];
    		
    		if(j - 1 >= 0){
    			dp[i][j][0] = (dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1]) * 1.0 * (1.0 - a[i - 1]);
    		}
    	}
    }
    dd res = 0.0;
    for(int i = 0; i <= B; i++){
    	res += dp[n][i][0] + dp[n][i][1];
    }
    cout << res << endl;
}


int32_t main(){
    // ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int tt = 1;
    // cin >> tt;
    cout << fixed << setprecision(12);
    for(int T = 1; T <= tt; T++){
        // cerr << endl << "Case #" << T << ": " << endl;
        test_cases();
    }
}