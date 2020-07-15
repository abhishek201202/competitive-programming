#include<bits/stdc++.h>
#define int long long
#define ff first
#define ss second
#define pb push_back
using namespace std;

const int MAX = 100001;
vector<int> primes;
void sieve(){
	bool isPrime[MAX];
	memset(isPrime , 1 , sizeof isPrime);
	for(int i = 2 ; i*i < MAX ; i++){
		if(!isPrime[i]) continue;
		for(int j = i*i ; j < MAX ; j += i){
			isPrime[j] = false;
		}
	}
	primes.pb(2);
	for(int i = 3 ; i < MAX ; i += 2){
		if(isPrime[i]) primes.pb(i);
	}
}

void printPrimes(int l,int r){
	// vector<bool> isPrime(r - l + 1 , true);
	bool isPrime[r -l + 1];
	memset(isPrime , 1 , sizeof isPrime);

	for(int i = 0 ; primes[i] * primes[i] <= r ; i++){
		int currPrime = primes[i];
		// Just smaller or equal value to l
		int base = (l / (currPrime)) * (currPrime);
		if(base < l) base += currPrime;

		// Mark all mutliples within L To R as false
		for(int j = base ; j <= r ; j += currPrime){
			isPrime[j - l] = false;
		}

		// There may be a case where base is itself a prime number .
		if(base == currPrime){
			isPrime[base - l] = true;
		}
	}

	for(int i = 0 ; i <= r - l ; i++){
		if(isPrime[i]){
			cout << i + l << endl;
		}
	}
}
int32_t main(){
	sieve();
	int t; cin >> t;
	while(t--){
		int l , r;
		cin >> l >> r;
		printPrimes(l , r);
	}
	return 0;
}