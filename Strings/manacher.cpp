#include<bits/stdc++.h>
#define int long long
#define ff first
#define ss second
#define pb push_back
using namespace std;

// return the vector with info that ith index is the centre 
// of palindrome having length equal to value at that index
// abbcbba == @#a#b#b#c#b#b#a#$ == size == 2*n + 3 == 
// to cover both odd and even cases of palindrome
template<typename T>
vector<int> manacher(T& s){
    if(s.size() == 0) return vector<int>();
    int n = s.size();
    vector<int> pal(2 * n + 3 , 0);

    int c = 1 , r_most = 1;
    for(int i = 2 ; i < 2 * n + 1 ; i++){
        int ref = c - (i - c); 
        pal[i] = max(0 , min(r_most - i , pal[ref]));
        int l = i - pal[i] - 1;
        int r = i + pal[i] + 1;
        while(l%2 != 0 || ( (l/2 - 1) >= 0 && (r/2 - 1) >= 0 
                           && s[l/2 - 1] == s[r/2 - 1])){
                pal[i]++;
                l--; r++;
        }
        if(i + pal[i] > r_most){
            r_most = i + pal[i];
            c = i;
        }
    }
    return pal;
}

int32_t main(){
	string s; cin >> s;
	vector<int> pal = manacher(s);
	for(int i = 0; i < pal.size() ; i++){
		cout << pal[i] << " ";
	}
	cout << endl;
}
/*
czcaba
pal : 0 0 1 0 3 0 1 0 1 0 3 0 1 0 0
*/