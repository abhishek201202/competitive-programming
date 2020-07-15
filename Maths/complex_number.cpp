#include<bits/stdc++.h>
#define int long long
#define ff first 
#define ss second
using namespace std;
typedef pair<int,int> pii; 

typedef complex<double> point; 
#include<complex>
#define x real() 
#define y imag() 
#define PI 3.1415926535897932384626 

double dot(point a,point b){
	return real(conj(a)*b);
}
double cross(point a,point b){
	return imag(conj(a)*b);	
}
point rotate(point a , point about , double theta){
	return (a - about) * polar(1.0 , theta) + about;
}
point reflect(point p , point about1 , point about2){
	point z = p - about1;
	point w = about2 - about1;
	return conj(z / w) * w + about1;
}
point intersect(point a,point b,point p,point q){
	// return intersection of line ab and pq
	double d1 = cross(p-a,b-a);
	double d2 = cross(q-a,b-a);
	return (d1 * q - d2 * p) / (d1 - d2);
}
point to_comp(pii a){
	return point(a.ff , a.ss);
}
int32_t main(){					
	point p1(3,4);
	cout << p1 << endl;
	point p2 = to_comp({-333,4});
	cout << p2 << endl;
}							

