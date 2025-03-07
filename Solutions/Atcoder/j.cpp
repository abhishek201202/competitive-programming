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
const int N   = 305;



void test_cases(){
	int n; cin >> n;
	vector<int> cnt(4, 0);
	for(int i = 0;i < n; i++){
		int x; cin >> x;
		cnt[x]++;
	}


	dd dp[N][N][N];
	dp[0][0][0] = 0.0;
	for(int three = 0; three <= n; three++){
		for(int two = 0; two <= n; two ++){
			for(int one = 0; one <= n; one++){
				int zero = n - three - two - one;
				if(zero == n) continue;
				if(one + two + three > n) continue;
				dp[three][two][one] = 1;
				if(three){
					dp[three][two][one] += (1.0 * three / n) * dp[three - 1][two + 1][one];
				}
				if(two){
					dp[three][two][one] += (1.0 * two / n) * dp[three][two - 1][one + 1];
				}
				if(one){
					dp[three][two][one] += (1.0 * one / n) * dp[three][two][one - 1];
				}
				dp[three][two][one] /= (1.0 - 1.0 * zero / n);
			}
		}
	}
	cout << dp[cnt[3]][cnt[2]][cnt[1]] << endl;
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