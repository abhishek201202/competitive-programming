#include<bits/stdc++.h>
#define int long long
#define ff first
#define ss second
#define pb push_back
using namespace std;


int32_t main(){
	int n; cin >> n; // total no of piles
	vector<int> v(n);
	// v[i] === >>> ith pile has v[i] stones
	for(int i = 0 ; i < n ; i++){
		cin >> v[i];
	}
	// nim theorem
	// if cumulative_xor == 0 === >>> 1st player always loos else win
	int cumulative_xor = 0;
	for(int i = 0 ; i < n ;i++){
		cumulative_xor ^= v[i];
	}
	if(!cumulative_xor){
		cout << "1st player loss" << endl;
	}else{
		cout << "1st player wins" << endl;
	}
}