#include<bits/stdc++.h>
using namespace std;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rng1(chrono::steady_clock::now().time_since_epoch().count());

int32_t main(){
	for(int i = 0; i < 5; i++){
		cout << rng() << " " << rand() << " " << rng1() << endl;
	}

	for(int i = 0; i < 10; i++){
		int cnt = 0;
		int n = 1000000;
		for(int j = 0; j < n; j++){
			if(rand()%2) cnt++;
		}
		// how far we are from the average value 
		// with probability 1/2
		cout << cnt << " " << abs(cnt - n/2) << endl;
	}
}