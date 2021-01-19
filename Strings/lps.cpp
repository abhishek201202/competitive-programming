#include<bits/stdc++.h>
#define int long long
#define ff first
#define ss second
#define pb push_back
using namespace std;

// LPS array is always generated for pattern which we have to find
// will give the vector whose ith index tells 
// the length of prefix which is also a suffix 
// ending at that index
template<typename T>
vector<int> lps(T s){
    int len = s.size();
    vector<int> LPS(len , 0);
    int i = 1 , j = 0;
    for(int i = 1; i < len; i++){
        int k = LPS[i - 1];
        while(k && s[k] != s[i]){
            k = LPS[k - 1];
        }
        if(s[k] == s[i]) k++;
        LPS[i] = k;
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