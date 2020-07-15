#include<bits/stdc++.h>
#define int long long
#define ff first
#define ss second
#define pb push_back
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
		if(!P[i]) Prime.pb(i);
	}
}

int32_t main(){
	sieve();
	for(int i = 0 ; i < 20 ; i++){
		cout << Prime[i] << " ";
	}
	cout << endl;

}