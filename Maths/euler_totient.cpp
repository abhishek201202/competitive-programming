#include<bits/stdc++.h>
#define int long long
#define ff first
#define ss second
#define pb push_back
using namespace std;

const int N = 1e6 + 5;
int phii[N];

// Euler Totient Function
void pre(){
	iota(phii, phii + N, 0);
	for(int i = 2; i < N; i++){
		if(phii[i] != i) continue;
		for(int j = i; j < N; j += i){
			phii[j] = phii[j] * (i - 1) / i;
		}
	}
}

int32_t main(){
	pre();
	int n; cin >> n;
	for(int i = 0 ;i <= n ;i++){
		cout << "i : " << i << " :: " << phii[i] << endl;
	}
}