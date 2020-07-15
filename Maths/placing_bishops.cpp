#include<bits/stdc++.h>
#define int long long
#define ff first
#define ss second
#define pb push_back
using namespace std;

int squares(int i){
	if(i&1){
		return i/4 * 2 + 1;
	}else{
		return (i - 1)/4 * 2 + 2;
	}
}

int placing_bishops(int n, int k){
	if(k > 2*n -1) return 0;
	vector<vector<int>> D(2*n , vector<int>(k + 1 , 0));
	D[1][1] = 1;
	for(int i = 0 ; i < 2*n ; i++){
		D[i][0] = 1;
	}
	for(int i = 2 ; i < 2*n ; i++){
		for(int j = 1 ; j <= k ; j++){
			// not sure b/w both the recursive relation , 1st one is on cp algorithm
			// D[i][j] = D[i - 2][j] + D[i - 2][j - 1] * (squares(i) - (j - 1));
			D[i][j] = D[i - 2][j] + D[i - 2][j - 1] * max(0ll , (squares(i) - (j - 1)));
		}
	}
	int res = 0;
	for(int i = 0 ; i <= k ; i++){
		res += D[2*n - 1][i] * D[2*n - 2][k - i];
	}
	return res;
}

int32_t main(){
	while(1){
		cout << endl << endl << "new test case ......." << endl;
		int n , k; cin >> n >> k;
		cout << placing_bishops(n , k) << endl;
		cout << bishop_placements(n , k) << endl;
	}
}