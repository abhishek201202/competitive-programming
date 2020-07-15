#include<bits/stdc++.h>
#define int long long
#define ff first
#define ss second
#define pb push_back
using namespace std;

bool trial_division(int n){
	for(int i = 2; i <= sqrt(n) ; i++){
		if(n%i == 0) return false;
	}
	return true;
}


bool fermat_primality(int n){
	if(n < 4) return n == 2 || n == 3;
	auto pow = [&](int a , int b , int m)->int{
		if(a == 0) return 0;
		int res = 1ll;
		a %= m;
		while(b > 0){
			if(b & 1ll){
				res = (res * a) % m;
			}
			a = (a * a) % m;
			b >>= 1ll;
		}
		return res;
	};
	int cnt1 = 0 , cnt0 = 0;
	for(int p = 0 ; p < 1e6 ; p++){
		int a = 2 + rand() % (n - 3);
		if(pow(a , n - 1 , n) != 1){
			cnt0 ++;
		}else{
			cnt1++;
		}
	}
	return (cnt1 >= cnt0) ? true : false;
}

int32_t main(){
	while(1){
		cout << endl << endl << "new test case ..........." << endl;
		int n; cin >> n;
		cout << "according to trial division   : " << trial_division(n) << endl;
		cout << "according to fermat_primality : " << fermat_primality(n) << endl;
	}
}