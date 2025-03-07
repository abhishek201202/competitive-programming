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

int n, k;

int brute_force(vector<vector<int>> &a, int n, int k){
	vector<int> dp(n, 1);
	for(int steps = 0; steps < k; steps ++){
		vector<int> new_dp(n);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(a[i][j]){
					new_dp[j] += dp[i];
				}
			}
		}
		dp = new_dp;
	}
	int res = 0;
	for(int i = 0; i < n; i++){
		res += dp[i];
	}
	return res;
} 




struct M{
	int n;
	vector<vector<int>> t;
	M(int n){
		this -> n = n;
		t.resize(n, vector<int>(n));
	}

	M operator* (const M& b) const{
		M c = M(n);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				for(int k = 0; k < n; k++){
					c.t[i][k] = (c.t[i][k] + (t[i][j] * b.t[j][k])%mod)%mod;
				}
			}
		}
		return c;
	}
};

void test_cases(){
	int n, k; cin >> n >> k;
	vector<vector<int>> a(n, vector<int>(n, 0));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> a[i][j];
		}
	} 

	M answer = M(n);
	for(int i = 0; i < n; i++){
		answer.t[i][i] = 1;
	}


	M F1 = M(n);
	F1.t = a;
	while(k){
		if(k&1){
			answer = answer  * F1;
		}
		F1 = F1 * F1;
		k /= 2;
	}
	int res = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			res = (res + answer.t[i][j])%mod;
		}
	}
	cout << res << endl;
	// cout << brute_force(a, n, k) << endl;
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