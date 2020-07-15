#include<bits/stdc++.h>
#define int long long
#define ff first
#define ss second
#define pb push_back
using namespace std;

const int mod = 1e9 + 7;

// ===== >>>>> When Value of m is very large <<<<< =====
// According to Fermat’s little theorem
// a^(p-1) mod p = 1, When p is prime.
// A^B mod M = ( A^(M-1) * A^(M-1) *.......* A^(M-1) * A^(x) ) mod M
// A ^ (M-1) mod M = 1
// A^B mod M = ( 1 * 1 * ....... * 1 * A^(x) ) mod M
// Hence mod B with M-1 to reduce the number to a smaller one 
// and then use power() method to compute (a^b)%m.


int pow(int a , int b , int m){
	if(b == 0) return 1;
	if(a == 0) return 0;
	int res = pow(a , b / 2 , m);
	res = ((res % m) * (res % m)) % m;
	if(b&1) res = (res * (a % m)) % m;
	return res;
}

int powI(int a , int b , int m){
	if(a == 0) return 0;
	a %= m;
	int res = 1;
	while(b > 0){
		if(b & 1ll){
			res = (res * a) % m;
		}
		a = (a * a) % m;
		b >>= 1ll;
	}
	return res;
}

int32_t main(){
	while(1){
		int a , b ; cin >> a >> b;
		cout << pow(a , b , mod) << endl;
		cout << powI(a , b , mod) << endl;
	}
}