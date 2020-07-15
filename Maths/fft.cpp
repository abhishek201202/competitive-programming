#include<bits/stdc++.h>
#define int long long
#define ff first
#define ss second
#define pb push_back
using namespace std;
typedef complex<double> base;


vector<base> fft(vector<base> &a , bool invert){
	int n = (int)a.size();
	if(n == 1){ // that mean degree is 0
		return a;
	}

	vector<base> a_even(n / 2) , a_odd(n / 2);
	for(int i = 0 , j = 0 ; i < n ;i += 2 , j++){
		a_even[j] = a[i];
		a_odd[j] = a[i + 1];
	}

	vector<base> y_even = fft(a_even , invert);
	vector<base> y_odd = fft(a_odd , invert);

	vector<base> y(n);
	double PI = acos(-1);
	double theta = (2 * PI) / n ;
	theta *= (invert ? -1ll : 1ll);
	base w(1) , wn(cos(theta) , sin(theta));
	for(int k = 0; k < n / 2 ; k ++){
		y[k] = y_even[k] + w * y_odd[k];
		y[k + n/2] = y_even[k] - w * y_odd[k];
		if(invert) y[k] /= 2 , y[k + n/2] /= 2;
		w *= wn;
	}
	return y;
}


vector<int> multiply(vector<int> &a , vector<int> &b){
	vector<base> fa(a.begin() , a.end());
	vector<base> fb(b.begin() , b.end());

	size_t n = 1;
	while(n < max(a.size() , b.size())) n <<= 1ll;
	n <<= 1;

	fa.resize(n) , fb.resize(n);
	vector<base> ya = fft(fa , false);
	vector<base> yb = fft(fb , false);
	for(int i = 0; i < n ; i++){
		ya[i] *= yb[i];
	}

	vector<base> yc = fft(ya , 1);
	vector<int> res(n);
	for(int i = 0 ;i < n ; i++){
		res[i] = (int)(yc[i].real() + 0.5);
	}
	return res;
}


int32_t main(){
	cout << fixed << setprecision(10);
	while(1){
		cout << endl << endl << "new text case .............." << endl;
		int n , m; cin >> n >> m;
		vector<int> a(n) , b(m);
		for(int i = 0 ;i < n ; i++){
			cin >> a[i];
		}
		for(int i = 0 ;i < m ; i++){
			cin >> b[i];
		}
		vector<int> c = multiply(a , b);
		for(int i  = 0 ;i < c.size() ; i++){
			cout << c[i] << " ";
		}
		cout << endl;
	}
}