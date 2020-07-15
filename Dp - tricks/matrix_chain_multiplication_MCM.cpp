#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ff first
#define ss second
#define pb push_back
#define int long long
typedef pair<int,int> pii;

const int mod = 1e9 + 7;
const int MOD = 998244353;
const int N = 1e3 + 5;

// matrix M[i] has dimension v[i - 1] * v[i] 
// matrices are start from index 1 and dimensions are from 0
int MCM(vector<int> v){
	int n = v.size();
	vector<vector<int>> dp(n , vector<int>(n , 1e9));
	// matrix(Chain) of length 1 
	for(int i = 0 ;i < n; i ++){
		dp[i][i] = 0;
	}
	// chain of length L
	for(int L = 2; L <= n - 1; L++){
		for(int i = 1; i + L - 1 < n; i++){ 
			int j = i + L - 1;
			for(int k = i ; k <= j - 1; k ++){
				dp[i][j] = min(dp[i][j] ,
				dp[i][k] + dp[k + 1][j] + (v[i - 1]*v[k]*v[j]));
			}
		}
	}
	return dp[1][n - 1];
}

int32_t main(){
    while(1){
    	cout << endl << endl << "new test case ............." << endl;
		int n; cin >> n;
		vector<int> v(n + 1);
		for(int i = 0 ;i < n + 1;  i++){
			cin >> v[i];
		}
		cout << MCM(v) << endl;
    }
}