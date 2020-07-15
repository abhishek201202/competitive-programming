#include<bits/stdc++.h>
#define int long long
#define ff first
#define ss second
#define pb push_back
using namespace std;

int pow(int a , int b, int m){
	if(a == 0) return 0;
	int res = 1ll;
	a %= m;
	while(b > 0){
		if(b & 1ll){
			res = (res * a) % m;
		}
		b >>= 1ll;
		a = (a * a) % m;
	}
	return res;
}
// (p - 1)_factorial % p = -1 
// use to compute n_factoral % p
int Wilson(int n , int p){
	if(n >= p) return 0;
	int ans = 1ll;
	for(int i = n + 1; i < p ; i++){
		ans = (ans * pow(i , p - 2 , p)) % p;
	}
	return (p - ans) % p;

}


int32_t main(){
	while(1){
		int n , p ; cin >> n >> p;
		cout << Wilson(n , p) << endl;
	}
}