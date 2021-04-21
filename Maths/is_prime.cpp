// https://www.spoj.com/problems/PON/
#include<bits/stdc++.h>
#define int long long int
using namespace std;

// passed all the test case in Google Codejam Round B 2021 
// Consecutive Primes
// working good for n <= 1e13 on spoj
bool miller_rabin(int n) { // returns true if n is probably prime, else returns false.
    if(n < 2 || n % 6 % 4 != 1) return n - 2 < 2;
    auto power = [&](uint64_t a, uint64_t b, uint64_t mod){
        uint64_t res = 1; a %= mod;
        while(b){
            if(b&1ll) res = (__uint128_t)res * a % mod;
            a = (__uint128_t)a * a % mod;
            b >>= 1;
        }
        return res;
    };
    int64_t A[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
    int s = __builtin_ctzll(n-1);
    int d = n >> s;
    for(int64_t a : A) {   // ^ count trailing zeroes
        int p = power(a, d, n), i = s;
        while (p != 1 && p != n-1 && a%n && i--) p = (p * p) % n;
        if (p != n-1 && i != s) return false;
    }
    return true;
}

// Didn't passed all the test case in Google Codejam Round B 2021 
// Consecutive Primes
// working good for n <= 2 ^ 64 on spoj
bool probablyPrimeFermat(int n, int iter = 5) {
    if(n < 4) return n == 2 || n == 3;
    auto power = [&](uint64_t a, uint64_t b, uint64_t mod){
        uint64_t res = 1; a %= mod;
        while(b){
            if(b&1ll) res = (__uint128_t)res * a % mod;
            a = (__uint128_t)a * a % mod;
            b >>= 1;
        }
        return res;
    };
    for(int i = 0; i < iter; i++) {
        int a = 2 + rand() % (n - 3);
        if(power(a, n - 1, n) != 1) return false;
    }
    return true;
}



int32_t main(){
	int tt; cin >> tt;
	while(tt--){
		int n; cin >> n;
		cout << (probablyPrimeFermat(n) ? "YES" : "NO") << endl;
    }
}