#include<bits/stdc++.h>
#define int long long
#define ff first
#define ss second
#define pb push_back
using namespace std;


vector<int> divisors(int n){
	// by this we also cal all pairs such that 
	// a * b == n
	vector<int> ans;
	for(int i = 1; i <= sqrt(n) ;i++){
		if(n%i != 0) continue;
		int a = n/i;
		int b = i;
		// a * b = n
		if(a == b) ans.pb(a);
		else ans.pb(a) , ans.pb(b);
	}
	return ans;
}

int32_t main(){
	int t = 1;
	cin >> t;
	while(t--){
		int n; cin >> n;
	}

}