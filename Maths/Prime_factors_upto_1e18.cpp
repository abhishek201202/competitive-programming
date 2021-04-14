// https://codeforces.com/gym/102861/problem/N
#include <bits/stdc++.h>
#define int long long
#define ALL(x) x.begin(), x.end()
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e6 + 5;

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


int mul(int a, int b, int mod){
    int ret = a * b - mod * (int)((long double)a * b / mod);
    ret = ret + (ret < 0 ? mod : 0);
    return ret;
}

int pow(int a, int b, const int mod) {
    if (b == 0) return 1;
    int res = pow(a,b/2,mod); 
    res = mul(res, res, mod);
    return b&1 ? mul(res,a,mod) : res;
}


bool isPrime(int n) { // returns true if n is probably prime, else returns false.
    if(n < 2 || n % 6 % 4 != 1) return n-2 < 2;
    int A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
    int s = __builtin_ctzll(n-1);
    int d = n >> s;
    for(int a : A) {   // ^ count trailing zeroes
        int p = pow(a,d,n), i = s;
        while (p != 1 && p != n-1 && a%n && i--) p = mul(p,p,n);
        if (p != n-1 && i != s) return 0;
    }
    return 1;
}


/* method to return prime divisor for n */
int PollardRho(int n){
    auto f = [n](int x) { return (mul(x,x,n)+1)%n; };
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


// Prime Factors upto 1e18
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


void test_cases(){
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


int32_t main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int tt = 1;
    // cin >> tt;
    sieve();
    for(int T = 1; T <= tt; T++){
        // cerr << endl << "Case #" << T << ": " << endl;
        test_cases();
    }
}
