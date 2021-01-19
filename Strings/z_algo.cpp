#include<bits/stdc++.h>
#define int long long
#define ff first
#define ss second
#define pb push_back
using namespace std;

// z[i] == length of longest substring
// starting at ith index , which is 
// also the prefix of the string 
template<typename T>
vector<int> Z(T s){
	int len = s.size();
	int l = 0 , r = 0 ;
	vector<int> z(len , 0);
	for(int i = 0 ; i < len ; i ++){
		if(i > r){
			// i does not lie b/w l and r
			// z for this doesn't exist
			l = i , r = i;
			while(r < len && s[r - l] == s[r]) r++ ;
			z[i] = (r--) - l;
		}else{
			if(i + z[i - l] <= r){
				// i lies b/w l and r 
				// z will exist previously
				z[i] = z[i - l];
			}else{
				// some part of z is already included 
				// you have to start matching further
				l = i;
				while(r < len && s[r - l] == s[r]) r++ ;
				z[i] = (r--) - l;
			}
		}
	}
	return z;
}


int32_t main(){
	string t , p ; cin >> t >> p;
	string s = p + '$' + t;
	vector<int> z = Z(s);
	for(int i = 0 ; i < z.size() ; i++){
		if(z[i] == p.size()){
			cout << i - p.size() - 1 << " ";
		}
	}
	cout << endl;
}