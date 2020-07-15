#include<bits/stdc++.h>
#define int long long
#define ff first
#define ss second
#define pb push_back
using namespace std;

const int mod = 1e9 + 7;
const int N = 1e7 + 5;
int fact[N] , inv[N];

int pow(int a , int b , int m){
	if(a == 0) return 0;
	a %= m;
	int res = 1ll;
	while(b){
		if(b&1) res = (res * a) % m;
		b >>= 1ll;
		a = (a * a) % m;
	}
	return res;
}

void pre(){
	fact[0] = inv[0] = inv[1] = fact[1] = 1;
	for(int i = 2 ;i < N ; i++){
		fact[i] = (fact[i - 1] * i) % mod;
		inv[i] = pow(fact[i] , mod - 2 , mod);
	}
}

int catalan(int n){
	// 2n_C_n / (n + 1)
	int ans = fact[2*n];
	ans = (ans * inv[n]) % mod;
	ans = (ans * inv[n]) % mod;
	ans = (ans * pow(n + 1 , mod - 2 , mod))  % mod;
	return ans;
}


int32_t main(){
	pre();
	while(1){
		cout << endl << endl << "new test case ......." << endl;
		int n; cin >> n;
		cout << catalan(n) << endl;
	}

}