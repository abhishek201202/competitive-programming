#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e6 + 5;
vector<int> Prime;
void sieve(){
    vector<int> P(N , 0);
    for(int i = 2 ; i < N ; i++){
        if(P[i]) continue;
        for(int j = i * i ; j < N ; j += i){
            P[j] = 1;
        }
    }
    for(int i = 2 ; i < N ; i++){
        if(!P[i]) Prime.push_back(i);
    }
}

vector<int> getPrime(int l,int r){
    bool isPrime[r - l + 1];
    for(int i = 0; i <= r - l; i++){
        isPrime[i] = true;
    }

    for(int i = 0; Prime[i] * Prime[i] <= r; i++){
        int currPrime = Prime[i];
        // Just smaller or equal value to l
        long long base = (l/(currPrime))*(currPrime);
        if(base < l){
            base = base + currPrime;
        }

        // Mark all mutliples within L To R as false
        for(long long j = base;j<=r ;j+= currPrime){
            isPrime[j-l] = false;
        }

        // There may be a case where base is itself a prime number .
        if(base == currPrime){
            isPrime[base-l] = true;
        }
    }

    vector<int> res;
    for(int i = 0;i<=r-l;i++){
        if(isPrime[i] == true && (i + l) != 1){
            res.push_back(i + l);
        }
    }
    return res;
}

void test_cases(){
    int l, r; cin >> l >> r;
    vector<int> P = getPrime(l, r);
    for(int x : P){
        cout << x << endl;
    }
}


int32_t main(){
    sieve();
    int tt = 1;
    cin >> tt;
    for(int T = 1; T <= tt; T++){
        // cerr << endl << "Case #" << T << ": " << endl;
        test_cases();
    }
}