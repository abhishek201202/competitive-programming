#include<bits/stdc++.h>
#define int long long 
#define ff first
#define ss second
#define pb push_back
#define mod 1000000007ll
using namespace std;

// 1st method
const int N = 1e7 + 5;
int inv[N];
void pre(){
	inv[0] = inv[1] = 1;
	for(int i = 2; i < N ; i ++){
		inv[i] = (mod - (inv[mod % i] * (mod/i))%mod)%mod;
	} 
}

// 2nd method
int inv_modulo(int a,int b = mod - 2,int m = mod){
	int res = 1; 
	a %= m;
	while(b > 0){ 
		if(b&1) res = (res*a)%m;
		b >>= 1ll;
		a = (a*a)%m;
	}
	return res;
}

// 3rd method :: By using Extended Euclid algorithm
// inverse is equal to the value of y
// this method is use irrespective of b is prime of not prime 
int Extended_euclid(int a , int b , int &x , int &y){
	if(a < b) swap(a , b);
	if(b == 0){
		x = 1;
		y = 0;
		return a;
	}
	int res = Extended_euclid(b , a % b , x , y);
	int temp = y;
	y = x - ((a / b) * y);
	x = temp;
	return res;
}

int32_t main(){
	pre();
	while(1){
		cout << endl << endl << "new test case ........." << endl;
		int a , x , y; cin >> a;
		cout << inv[a] << endl;
		cout << inv_modulo(a) << endl;
		Extended_euclid(min(a , mod) , max(a , mod) , x , y);
		cout << (y + mod) % mod << endl;
	}
}