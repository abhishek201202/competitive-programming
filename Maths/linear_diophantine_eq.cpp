#include<bits/stdc++.h>
#define int long long
#define ff first
#define ss second
#define pb push_back
using namespace std;

int gcd(int a , int b, int &x ,int &y){
	if(a < b) swap(a , b);
	if(b == 0){
		x = 1;
		y = 0;
		return a;
	}
	int res = gcd(b , a % b , x , y);
	int temp = y;
	y = x - (a / b) * y;
	x = temp;
	return res;
}

// ax + by = n
pair<int,int> LinearDiophantine(int a , int b , int n){
	int x , y;
	int G = gcd(a , b , x , y);
	if(n % G) return {1e18 , 1e18};
	x *= n / G;
	y *= n / G;
	if(a < 0) x = -x;
	if(b < 0) y = -y;
	return {x , y};
}

int32_t main(){
	while(1){
		cout << endl << endl << "new tes case ............" << endl;
		int a , b , n; cin >> a >> b >> n;
		pair<int,int> p = LinearDiophantine(a , b , n);
		cout << p.ff << " " << p.ss << endl;
	}

}