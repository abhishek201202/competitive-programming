#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ff first
#define ss second
#define pb push_back
#define int long long
typedef pair<int,int> pii;

const int mod = 1e9 + 7;
const int MOD = 998244353;
const int N = 5e5 + 5;

template<typename T>
int LIS(T& a){
	T tail;
	tail.pb(a[0]);
	for(int i = 1 ; i < a.size(); i ++){
		if(a[i] < tail[0]){
			tail[0] = a[i];
		}else if(a[i] > tail.back()){
			tail.pb(a[i]);
		}else{
			int ind = lower_bound(tail.begin(), tail.end(), a[i]) - tail.begin();
			tail[ind] = a[i];
		}
	}
	return tail.size();
}

// Using Multisets and Sets

int32_t main(){
    while(1){
    	cout << endl << endl << "new test case .........." << endl;
		int n; cin >> n;
		vector<int> v(n);
		for(int i = 0 ;i < n; i ++){
			cin >> v[i];
		}
		cout << LIS(v) << endl;
    }
}