#include<bits/stdc++.h>
#define int long long
#define ff first
#define ss second
using namespace std;

// (x^n)%m = ??
// when n is very large and m can be prime or composite

int powI(int a, int b, int m){
	a %= m;
	int res = 1ll;
	while(b){
		if(b&1){
			res = (res * a) % m;
		}
		b >>= 1;
		a = (a * a) % m;
	}
	return res;
}

// when m is prime numer
int POW_Prime(int a, string b, int m){
	int x = 0;
	for(int i = 0; i < b.size(); i++){
		x = (x * 10 + (b[i] - '0')) % (m - 1);
	}
	return powI(a, x, m);
}


// when m is not prime number

vector<int> Euler(int n){
    vector<int> E(n + 1);
    for(int i = 0 ;i <= n ;i++) E[i] = i;
    for(int i = 2; i <= n ;i++){
        if(E[i] != i) continue;
        E[i] = i - 1;
        for(int j = 2 * i ; j <= n ; j += i){
            E[j] = E[j] * (i - 1) / i;
        }
    }
    return E;
}
int POW_Composite(int a, string b, int m){
	vector<int> E = Euler(m);
	int phii_m = E[m];
	int x = 0;
	for(int i = 0; i < b.size(); i++){
		x = (x * 10 + (b[i] - '0')) % phii_m;
	}
	if(x == 0) x += phii_m;
	return powI(a, x, m);
}



int32_t main(){


}