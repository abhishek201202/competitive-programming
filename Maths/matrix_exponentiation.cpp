// https://www.spoj.com/problems/SEQ/
#include<bits/stdc++.h>
#define int long long
#define dd long double
#define ff first
#define ss second
#define pb push_back
using namespace std;

const int mod = 1e9 + 7;

int k;
vector<int> a , b , c;

struct M{
	dd n, m;
	vector<vector<dd>> t;
	M(int n, int m){
		this -> n = n;
		this -> m = m;
		t.resize(n, vector<dd>(m, 1.0));
	}

	M operator* (const M& b) const{
		M c = M(n, b.m);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < b.m; j++){
				for(int k = 0; k < b.n; k++){
					c.t[i][k] = (c.t[i][k] + (t[i][j] * b.t[j][k]));
				}
			}
		}
		return c;
	}
};

template<typename T>
T pow(T a, int b){
	M res = M(a.n, a.m);
	while(b){
		if(b&1){
			res = res * a;
		}
		b >>= 1ll;
		a = a * a;
	}
	return res;
}



vector<vector<int>> multiply(vector<vector<int>> A , vector<vector<int>> B){
	vector<vector<int>> C(k + 1 , vector<int>(k + 1 , 0));
	for(int i = 1; i <= k ; i++){
		for(int j = 1 ; j <= k ; j++){
			for(int x = 1; x <= k ; x ++){
				C[i][j] = (C[i][j] + (A[i][x] * B[x][j])%mod ) % mod;
			}
		}
	}
	return C;
}


vector<vector<int>> pow(vector<vector<int>> A , int p){
	if(p == 1) return A;
	vector<vector<int>> res = pow(A , p/2);
	res = multiply(res , res);
	if(p&1){
		res = multiply(A , res);
	}
	return res;
}

int compute(int n){
	if(n == 0) return 0;
	if(n <= k) return b[n - 1];

	// make F1 matrix indexing start from 1
	vector<int> F1(k + 1);
	for(int i = 1 ; i <= k ; i++){
		F1[i] = b[i - 1];
	}

	// make Transformation matrix
	vector<vector<int>> T(k + 1 , vector<int>(k + 1 , 0));
	for(int i = 1; i <= k ; i++){
		for(int j = 1; j <= k ; j++){
			if(i < k && j == i + 1) T[i][j] = 1;
			if(i == k) T[i][j] = c[k - j];
		}
	}


	T = pow(T , n - 1);

	int res = 0;
	for(int i = 1; i <= k ; i++){
		res = (res + (T[1][i] * F1[i])%mod)% mod; 
	}
	return res;
}


int32_t main(){
	int tt = 1; cin >> tt;
	while(tt--){
		cin >> k;

		// init vector F1
		for(int i = 0; i < k ; i ++){
			int x; cin >> x;
			b.pb(x);
		}

		// Coefficients
		for(int i = 0 ;i < k ; i ++){
			int x; cin >> x;
			c.pb(x);
		}
		int n; cin >> n;
		cout << compute(n) << endl;

		a.clear() , b.clear() , c.clear();
	}
}