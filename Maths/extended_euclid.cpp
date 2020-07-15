#include<bits/stdc++.h>
#define int long long
#define ff first
#define ss second
#define pb push_back
using namespace std;


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

int32_t main(){
	while(1){
		cout << endl << endl << "new test case ........." << endl;
		int a , b; cin >> a >> b;
		int x , y;
		cout << "gcd : " << Extended_euclid(a , b , x , y) << " ";
		cout << "x : " << x << " y : " << y << endl;
	}	
}