#include<bits/stdc++.h>
#define int long long
#define ff first
#define ss second
#define pb push_back
using namespace std;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
// time complexity === >>> O(Nloglog(N))
// but limited with the size of lowP array
const int N = 1e5 + 5;
int lowP[N];
// lowP[i] it is the lowest prime factor of i 
void sieve(){
	memset(lowP , 0 ,sizeof lowP);
	for(int i = 2; i < N ; i++){
		if(lowP[i]) continue;
		lowP[i] = i;
		for(int j = i * i ; j < N ; j += i){
			if(!lowP[j]) lowP[j] = i;
		}
	}
}
vector<int> Prime_factors_using_sieve(int n){
	vector<int> res;
	while(n > 1){
		int curr = lowP[n];
		res.pb(curr);
		while(n%curr == 0) n /= curr; 
	}
	sort(res.begin() , res.end());
	return res;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
// time complexity === >>> o(sqrt(n))
vector<int> Prime_factors(int n){
	vector<int> res;
	if(n % 2 == 0) res.pb(2);
	while(n%2 == 0) n /= 2;
	for(int i = 3 ; i <= sqrt(n) ; i++){
		if(n%i == 0) res.pb(i);
		while(n%i == 0) n /= i;
	}
	if(n >= 2) res.pb(n);
	return res;
}

int32_t main(){
	sieve();

	while(1){
		int n ; cin >> n;
		vector<int> fact = Prime_factors(n);
		for(int i = 0; i < fact.size() ; i++){
			cout << fact[i] << " ";
		}
		cout << endl;

		vector<int> fact2 = Prime_factors_using_sieve(n);
		for(int i = 0; i < fact2.size() ; i++){
			cout << fact2[i] << " ";
		}
		cout << endl;
	}
}