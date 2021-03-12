// Tested on :: https://codeforces.com/gym/101982 (B - Coprime Integer)
#include<bits/stdc++.h>
using namespace std;

const int N = 2e7 + 5;
int lpf[N], Mobius[N];


void pre(){
	for(int i = 2; i < N; i++){
		if(lpf[i]) continue;
		for(int j = i; j < N; j += i){
			if(!lpf[j]) lpf[j] = i;
		}
	}
	Mobius[1] = 1;
	for(int i = 2; i < N; i++){
		if(lpf[i / lpf[i]] == lpf[i]){
			Mobius[i] = 0;
		}else{
			Mobius[i] = -1 * Mobius[i / lpf[i]];
		}
	}
}

int32_t main(){
	pre();
	int a, b, c, d; cin >> a >> b >> c >> d;
	long long res = 0;
	for(int k = 1; k <= max(b, d); k++){
		res += Mobius[k] * 1ll *  max(0, (b/k - (a - 1)/k)) * 1ll * max(0, (d/k - (c - 1)/k));
	}
	cout << res << endl;
}