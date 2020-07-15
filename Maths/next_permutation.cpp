#include<bits/stdc++.h>
#define int long long
#define ff first
#define ss second
#define pb push_back
using namespace std;


template<typename T>
void next_permutation(T &s){
	int ei = s.size() - 2;
	while(ei >= 0 && s[ei] >= s[ei + 1]) ei--;
	if(ei < 0) {
		reverse(s.begin() , s.end());
		return ;
	}
	reverse(s.begin() + ei + 1 , s.end());
	int ind = upper_bound(s.begin() + ei + 1 , s.end() , s[ei]) - s.begin();
	swap(s[ind] , s[ei]);
}

int32_t main(){
	while(1){
		cout << endl << endl << "new test case..........." << endl;
		string s; cin >> s;
		next_permutation(s);
		cout << s<< endl;
	}

}