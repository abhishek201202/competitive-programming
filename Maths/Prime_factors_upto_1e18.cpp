// https://codeforces.com/gym/102861/problem/N
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
#define debugg(...) {cerr << "[Line " << __LINE__ << "] :: "; dbg_out(split(#__VA_ARGS__, ',').begin(), __VA_ARGS__);}
#define READ(...) READ_OUT(split(#__VA_ARGS__, ',').begin(), __VA_ARGS__);

#define       endl             "\n"
#define       ff               first
#define       ss               second
#define       int              long long
#define       dd               long double
#define       ALL(x)           x.begin(), x.end()
#define       FOR(i, s, e)     for(int i = s; i <= e; i++)
#define       FORR(i, s, e)    for(int i = s; i >= e; i--)
#define       getcurrtime      ((double)clock()/CLOCKS_PER_SEC)
template<typename T> using pbds = tree<T, null_type, less<T>, rb_tree_tag ,tree_order_statistics_node_update>; 

const int mod = 1e9 + 7;
const int MOD = 998244353;
const int N   = 2e6 + 5;



vector<int> Prime;
void sieve(){
    vector<int> P(N , 0);
    for(int i = 2 ; i < N ; i++){
        if(P[i]) continue;
        for(int j = i * i ; j < N ; j += i){
            P[j] = 1;
        }
    }
    for(int i = 2 ; i < N ; i++){
        if(!P[i]) Prime.push_back(i);
    }
}


int modMint(int a, int b, const int mod) {
    int ret = a*b-mod*(int)((long double)a*b/mod);
    return ret+((ret<0)-(ret>=(int)mod))*mod; }

// int modMint(int a, int b, int mod){
// 	a = (a%mod + mod)%mod;
// 	b = (b%mod + mod)%mod;
// 	return (a * b)%mod;
// }

int modPow(int a, int b, const int mod) {
    if (b == 0) return 1;
    int res = modPow(a,b/2,mod); res = modMint(res,res,mod);
    return b&1 ? modMint(res,a,mod) : res;
}
bool isPrime(int n) { // returns true if n is probably prime, else returns false.
    if (n < 2 || n % 6 % 4 != 1) {
    	return n-2 < 2;
    }
    int A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022},
        s = __builtin_ctzll(n-1), d = n>>s;
    for(int a : A) {   // ^ count trailing zeroes
        int p = modPow(a,d,n), i = s;
        while (p != 1 && p != n-1 && a%n && i--) p = modMint(p,p,n);
        if (p != n-1 && i != s) return 0;
    }
    return 1;
}


/* method to return prime divisor for n */
int PollardRho(int n){
    auto f = [n](int x) { return (modMint(x,x,n)+1)%n; };
    if (!(n&1)) return 2;
    for (int i = 2;;++i) {
        int x = i, y = f(x), p;
        while((p = __gcd(n+y-x,n)) == 1) {
            x = f(x);
            y = f(f(y));
        }
        if (p != n) return p;
    }
}

vector<int> PrimeFactors(int n){
	vector<int> res;
	for(int p : Prime){
		if(p * p > n) break;
		if(n%p != 0) continue;
		res.push_back(p);
		while(n%p == 0) n /= p;
	}
	if(isPrime(n)){
		res.push_back(n);
		n = 1;
	}
	if(n != 1){
		int p = PollardRho(n);
		n /= p;
		res.push_back(p);
	}
	if(n != 1) res.push_back(n);
	return res;
}





int32_t main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    sieve();


    int m, n, k; cin >> m >> n >> k;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = 0; i < k; i++){
		int x, y, z; cin >> x >> y >> z;
	}
	vector<int> res;
	for(int i = 0; i < n; i++){
		for(int x : PrimeFactors(a[i])){
			res.push_back(x);
		}
	}
	sort(ALL(res));
	res.resize(distance(res.begin(), unique(ALL(res))));
	if(res[0] == 1){
		res.erase(lower_bound(ALL(res), 1));
	}
	for(int x : res){
		cout << x << " ";
	}
	cout << endl;
}