// https://cp-algorithms.com/combinatorics/inclusion-exclusion.html
// Task: given two numbers n and r, count the number of integers in the 
// interval [1;r] that are relatively prime to n (their gcd is 1).
#include<bits/stdc++.h>
#define int long long
#define ff first
#define ss second
#define pb push_back
using namespace std;

// a1_U_a2_U.....U_an = a1 + a2 + ..... + an + a1_a2 + .... + an_an-1 + .....
// a1_U_a2_U.....U_an == >> (sum of all odd sets) - (sum of all even sets)

int solve(int n , int r){
	vector<int> p;
	for(int i = 2; i <= sqrt(n) ; i++){
		if(n%i == 0) p.pb(i);
		while(n%i == 0) n /= i;
	}
	if(n >= 2) p.pb(n);

	int sum = 0;
	for(int mask = 1 ; mask < (1ll << p.size()) ; mask ++){
		int prod = 1ll , cnt = 0;
		for(int i = 0 ;i < p.size() ; i++){
			if(mask & (1ll << i)){
				cnt++ , prod *= p[i];
			}
		}
		int curr_set = r / prod;
		if(cnt&1) sum += curr_set;
		else sum -= curr_set;
	}
	return r - sum;
}


int32_t main(){
	while(1){
		cout << endl << endl << "new test case ..........." << endl;
		int n , r; cin >> n >> r;
		cout << solve(n , r) << endl;
	}
}