#include<bits/stdc++.h>
#define int long long
#define ff first
#define ss second
#define pb push_back
using namespace std;


// will give the vector whose ith index tells 
// the length of prefix which is also a suffix 
// ending at that index
template<typename T>
vector<int> lps(T s){
	int len = s.size();
	vector<int> LPS(len , 0);
	int l = 0, r = 1;
	while(r < len){
		if(s[r] == s[l]){
			LPS[r++] = (l++) + 1;
		}else{
			(l != 0) ? l = LPS[l - 1] : LPS[r++] = 0;
		}
	}
	return LPS;
}

int32_t main(){
	string s; cin >> s;
	vector<int> LPS = lps(s);
	for(int i = 0 ; i < LPS.size() ; i++){
		cout << LPS[i] << " ";
	}
	cout << endl;
}
/*
ssszzzzsssz
LPS : 0 1 2 0 0 0 0 1 2 3 4
*/