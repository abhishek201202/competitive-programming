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
vector<int> kmp(T t , T p){
	vector<int> LPS = lps(p);
	vector<int> KMP(t.size(), 0);
	for(int i = 0, j = 0; i < t.size(); i++){
		while(j && t[i] != p[j]){
			j = LPS[j - 1];
		}
		if(t[i] == p[j]) j++;
		if(j == p.size()){
			KMP[i - p.size() + 1] = 1;
		}
	}
	return KMP;
}

int32_t main(){
	string p , t;
	cin >> p >> t;
	vector<int> KMP = kmp(t, p);
	int res = 0;
	for(int i = 0; i < KMP.size(); i++){
		res += KMP[i];
	}
	cout << res << endl;
}
/*
ABABDABACDABABCABAB
ABABCABAB
*/