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

/* 
Variables need to traverse on segment tree
1. si, ei of tree
2. node of segment tree
*/
struct SegmentTree{
	int n;
	vector<int>  T;
	SegmentTree(int n){
		this-> n = n;
		T.resize(4 * n, 0);
	}

	int qry(int l, int r, int node, int si, int ei){
		if(l > ei || r < si){
			return -1e9;
		}
		if(l <= si && r >= ei){
			return T[node];
		}
		int mid = (si + ei)/2;
		int L = qry(l, r, 2 * node, si, mid);
		int R = qry(l, r, 2 * node + 1, mid + 1, ei);
		return max(L, R);
	}
	int qry(int l, int r) { return qry(l, r, 1, 0, n - 1);}

	void update(int idx, int val, int node, int si, int ei){
		if(si == ei){
			T[node] = max(T[node], val);
			return;
		}
		int mid = (si + ei) / 2;
		if(idx <= mid){
			update(idx, val, 2 * node, si, mid);
		}else{
			update(idx,val, 2 * node + 1, mid + 1 , ei);
		}
		T[node] = max({T[node], T[2 * node], T[2 * node + 1]});
	}
	void update(int idx, int val){ update(idx, val, 1, 0, n - 1);}
};

void test_cases(){
	int n; cin >> n;
	vector<int> h(n), a(n);
	for(int i = 0; i < n; i++){
		cin >> h[i];
	}
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	SegmentTree seg(*max_element(ALL(h)) + 1);
	vector<int> dp(n, 0);
	for(int i = 0; i < n; i++){
		dp[i] = max(a[i], seg.qry(1, h[i] - 1) + a[i]);
		seg.update(h[i], dp[i]);

		// for(int j = 0; j < i; j++){
		// 	if(h[i] > h[j]){
		// 		dp[i] = max(dp[i], dp[j] + a[i]);
		// 	}
		// }
	}
	int res = 0;
	for(int i = 0; i < n; i++){
		res = max(res, dp[i]);
	}
	cout << res << endl;
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