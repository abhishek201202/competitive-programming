#include<bits/stdc++.h>
#define int long long
#define ff first
#define ss second
#define pb push_back
using namespace std;


const int N = 1e5 + 5;
const int K = 25;
int n; 
int arr[N] , dp[K][N] , logs[N];
// logs[i] means such maximum p such that 2^p <= i
// dp[i][j] means minimum in the subrange of length 2^i 
// from the position j.

void computelogs(){
	for(int i = 2 ; i < N ; i++){
		logs[i] =  logs[i / 2] + 1;
	}
}

void build_sparse(){
	for(int i = 0 ; i < N ; i++){
		dp[0][i] = arr[i];
	}
	for(int len = 1; len < K ; len++){
		for(int i = 0 ; i < n ;i++){
			dp[len][i] = min(dp[len - 1][i] , dp[len - 1][i + (1ll << len)]);
		}
	}
}

// normal query which take O(logn) time.
int query(int l , int r){
	int len = r - l + 1;
	int ans = 1e18;
	for(int i = 0 ; i <  K ; i++){
		if((len >> i)&1){
			ans = min(ans , dp[(1ll << i)][l]);
			l += (1ll << i);
		}
	}
	return ans;
}

// for indempotent function like min , max , gcd , lcm
int queryI(int l , int r){
	return min( dp[r - l + 1][l] , dp[r - l + 1][r - (1ll << (r - l + 1)) + 1] ) ;
}

int32_t main(){
	cin >> n;
	for(int i = 0 ; i < n ;i++){
		cin >> arr[i];
	}
}