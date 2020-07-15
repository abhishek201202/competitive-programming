#include<bits/stdc++.h>
#define int long long
#define ff first
#define ss second
#define pb push_back
using namespace std;

// simpson formula 
// ∫ a_to_b of f(x)dx ≈ 
// (f(x0) + 4f(x1) + 2f(x2) + 4f(x3) + 2f(x4) +.....+ 4f(x2N−1) + f(x2N)) *(h / 3)


const int N = 1e6; // no. of steps 

double f(int x){
	// let say function is f(x) = x^2 - 25
	return x*x - 25;
}

double integration(double a , double b){
	double h = (b - a) / N;
	double area = f(a) + f(b);
	for(int i = 1; i < N ; i++){
		double x = a + h * i;
		area += f(x) * ((i&1)? 4 : 2);
	}
	area *= h/3.0;
	return area;
}

int32_t main(){
	while(1){
		cout << endl << endl << "new test case .........." << endl;
		int a , b; cin >> a >> b;
		cout << integration(a , b) << endl;
	}
}