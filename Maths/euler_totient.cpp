#include<bits/stdc++.h>
#define int long long
#define ff first
#define ss second
#define pb push_back
using namespace std;

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

int32_t main(){
	int n; cin >> n;
	vector<int> E = Euler(n);
	for(int i = 0 ;i <= n ;i++){
		cout << "i : " << i << " :: " << E[i] << endl;
	}
}