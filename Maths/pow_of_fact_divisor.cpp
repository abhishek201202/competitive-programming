#include<bits/stdc++.h>
#define int long long
#define ff first
#define ss second
#define pb push_back
using namespace std;

// You are given two numbers n and k. 
// Find the largest power of k such that n! is divisible by kx.
// ex. use to find no of trailing zeros in 100!
int fact_pow(int n , int k){
	int temp = k;
	vector<pair<int,int>> P;
	for(int i = 2;  i <= sqrt(k) ; i++){
		bool ff = false;
		if(k%i == 0) ff = true;
		int cnt = 0;
		while(k%i == 0) k /= i , cnt++;
		if(ff)
			P.pb({i , cnt});
	}
	if(k >= 2) P.pb({k , 1});
	k = temp;
	int res = 1e18;
	for(int i = 0 ; i < P.size() ; i++){
		int curr = P[i].ff;
		int cnt = 0;
		temp = n;
		while(temp > 1){
			cnt += temp / curr;
			temp /= curr;
		}
		res = min(res , cnt / P[i].ss);
	}
	return res;
}

int32_t main(){
	while(1){
		cout << endl << endl << "new test case ........" << endl;
		int n , k; cin >> n >> k;
		cout << fact_pow(n , k) << endl;
	}
}