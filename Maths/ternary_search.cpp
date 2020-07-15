// https://www.codechef.com/problems/ICM2003
// useful to calculate value of x on which the funciton is max. or min.
#include<bits/stdc++.h>
#define int long long
#define ff first
#define ss second
#define pb push_back
using namespace std;

const double PI = acos(-1);
const double eps = 1e-9;   
double f(double x , double b , double c){
    double ans = x * x + b * x + c ;
    ans /= sin(x);
    return ans;
}
double ternary_search(double l, double r , double b , double c) {
    while(r - l > eps) {
        double m1 = l + (r - l) / 3.0;
        double m2 = r - (r - l) / 3.0;
        double f1 = f(m1 , b , c);      
        double f2 = f(m2 , b , c);      
        if (f1 > f2) l = m1; // sign depends upon the curvature of the function
        else r = m2;
    }
    return f(l , b , c);                    
}
int32_t main(){
	int tt; cin >> tt;
	while(tt--){
		cout << fixed << setprecision(10) ;
	    double b , c; cin >> b >> c;
	    double l = 0 + eps , r = (PI / 2.0) - eps;
	    cout << ternary_search(l , r , b , c) << endl;
	}
}