#include<bits/stdc++.h>
#define int long long
#define ff first 
#define ss second
#define pb push_back
using namespace std;

// range sum query
const int N = 1e5 + 5;
int arr[N] , dp[(int)sqrt(N) + 1] ; 
int n;


void build(){
	int rn = sqrt(n);
	int id = -1;
	for(int i = 0 ; i <  n ; i++){
		if(i % rn == 0) id++;
		dp[id] += arr[i];
	}
}

void update(int index , int val){
	int id = index / sqrt(n);
	dp[id] += val - arr[index];
	arr[index] = val;
}

int query(int l , int r){
	int ans = 0;
	int rn = sqrt(n);
	
	// left part of the block
	while(l < r && l != 0 && l % rn != 0){
		ans += arr[l];
		l++;
	}

	// middle part of the block
	while((l + rn) <= r){
		ans += dp[l/rn];
		l += rn;
	}

	// right part of the block
	while(l <= r){
		ans += arr[l];
		l++;
	}
	return ans;
}

int32_t main(){
	cin >> n;
	for(int  i = 0; i  < n ; i ++){
		cin >> arr[i];
	}
}