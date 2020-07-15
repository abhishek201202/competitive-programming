#include<bits/stdc++.h>
#define int long long
#define ff first
#define ss second
#define pb push_back
using namespace std;


const int N = 1e5 + 5;
int num[N] , rem[N];
int n;

int Extended_euclid(int a , int b , int &x , int &y){
	if(a < b) swap(a , b);
	if(b == 0){
		x = 1;
		y = 0;
		return a;
	}
	int res = Extended_euclid(b , a % b , x , y);
	int temp = y;
	y = x - ((a / b) * y);
	x = temp;
	return res;
}

int CRT(){
	int prod = 1;
	for(int i = 0 ;i < n ;i++){
		prod *= num[i];
	}
	
	int res = 0;
	for(int i = 0 ; i < n ;i++){
		int pp = prod / num[i];
		int inv  , y;
		Extended_euclid(pp , num[i] , inv , y);
		inv = (inv + num[i]) % num[i];
		res += rem[i] * pp * inv;
	}
	return res % prod;
}

int32_t main(){
	while(1){
		cin >> n;
		for(int i = 0; i < n ; i++){
			cin >> num[i];
		}
		for(int i = 0; i < n ;i++){
			cin >> rem[i];
		}
		cout << CRT() << endl;
	}
}
/*
3
3 4 5
2 3 1
*/