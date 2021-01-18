#include<bits/stdc++.h>
#define int long long
#define ff first
#define ss second
#define pb push_back
using namespace std;


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

template<typename T>
int KMP(T s , T p){
	int slen = s.size();
	int plen = p.size();
	int si = 0 , pi = 0;
	vector<int> LPS = lps(p);
	while(pi < plen && si < slen){
		if(s[si] == p[pi]){
			si ++ , pi ++ ;
		}else{
			(pi != 0)? pi = LPS[pi - 1] : si++; 
		}
	}
	return pi == plen ? 1 : 0;
}

int32_t main(){
	string s , p;
	cin >> s >> p;
	cout << KMP(s , p) << endl;
}
/*
ABABDABACDABABCABAB
ABABCABAB
*/