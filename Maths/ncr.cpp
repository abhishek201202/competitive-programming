#include<bits/stdc++.h>
#define int long long
#define ff first
#define ss second
#define pb push_back
using namespace std;

const int mod = 1e9 + 7;
const int N = 1e5 + 5;
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
	if(r > n) return 0;
	int ans = fact[n];
	ans = (ans * inv[n - r]) % mod;
	ans = (ans * inv[r]) % mod;
	return ans;
}

int32_t main(){
	pre();
	// for(int i = 0 ;i < 25 ; i++){
	// 	cout << fact[i] << " " << inv[i] << endl;
	// }
	while(1){
		cout << endl << endl << "new test case ..........." << endl;
		int n , r; cin >> n >> r;
		cout << ncr(n , r) << endl;
	}
}
