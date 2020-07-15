#include<bits/stdc++.h>
#define int long long
#define ff first
#define ss second
#define pb push_back
using namespace std;

const int N = 1e3;
int ncr[N][N];

void pascal(){
	for(int n = 0 ; n < N ; n++){
		ncr[n][0] = 1;
	}
	for(int n = 1 ; n < N ; n ++){
		for(int r = 1 ; r <= n ; r ++){
			ncr[n][r] = ncr[n - 1][r - 1] + ncr[n - 1][r];
		}
	}
}

int32_t main(){
	pascal();
	while(1){
		cout << endl << endl << "new test case ........" << endl;
		int n , r; cin >> n >> r;
		cout << ncr[n][r] << endl;
	}
}