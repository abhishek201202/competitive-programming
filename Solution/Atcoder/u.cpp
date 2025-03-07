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

vector<int> dp1, dp;

void rec(int idx, vector<int> &not_taken, int mask, int grp, int prev_score){
	if(idx == not_taken.size()){
		dp[mask] = max(dp[mask], dp1[grp] + prev_score);
		return;
	}
	rec(idx + 1, not_taken, mask, grp, prev_score);
	rec(idx + 1, not_taken, mask ^ (1ll << not_taken[idx]), grp ^ (1ll << not_taken[idx]), prev_score);
}

void test_cases(){
	int n; cin >> n;
	int a[n][n];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> a[i][j];
		}
	}
	dp1.resize(1ll << n, 0);
	for(int mask = 0; mask < (1ll << n); mask++){
		for(int i = 0; i < n; i++){
			for(int j = i + 1; j < n; j++){
				if((mask & (1ll << i)) && (mask & (1ll << j))){
					dp1[mask] += a[i][j];
				}
			}
		}
	}
	dp.resize(1ll << n, 0);
	for(int mask = 0; mask < (1ll << n); mask++){
		vector<int> not_taken;
		for(int bit = 0; bit < n; bit++){
			if(!(mask & (1ll << bit))){
				not_taken.push_back(bit);
			}
		}
		rec(0, not_taken, mask, 0, dp[mask]);
	}
	cout << dp[(1ll << n) - 1] << endl;
}


int32_t main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int tt = 1;
    // cin >> tt;
    for(int T = 1; T <= tt; T++){
        // cerr << endl << "Case #" << T << ": " << endl;
        test_cases();
    }
}