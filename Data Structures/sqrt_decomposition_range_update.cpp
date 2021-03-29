// https://www.hackerearth.com/problem/algorithm/final-question/
#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
const int MOD = 998244353;
const int N   = 5e5 + 5;

int n, q, k;
int a[N];
int sqt[(int)sqrt(N) + 1][1005];
int up[(int)sqrt(N) + 1]; 

void update(int l, int r, int val){
	int sz = sqrt(n);
	int bid = l/sz;
	// Left Block
	for(int i = l - l%sz; i%sz != 0; i++){
		a[i] = (a[i] + up[bid])%k;
	}
	up[bid] = 0;
	while(l < r && l%sz != 0){
		sqt[a[l]%k]--;
		sqt[(a[l] + val)%k]++;
		a[l] = (a[l] + val)%k;
		l++;
	}

	// Middle BLock
	while((l + sz) <= r){
		up[l/sz] += val%k;
		l += sz;
	}

	// Right Block
	bid = l/sz;
	for(int i = l; i%sz != 0; i++){
		a[i] = (a[i] + up[bid])%k;
	}
	while(l <= r){
		sqt[a[l]%k]--;
		sqt[(a[l] + val)%k]++;
		a[l] = (a[l] + val)%k;
		l++;
	}

}

int qry(int l, int r){
	int sz = sqrt(n);
	int res = 0;
	while(l < r && l != 0 && l%sz != 0){
		res += (a[l]%k == 0);
		l++;
	}
	while(l + sz <= r){
		res += sqt[l/sz];
		l += sz;
	}
	while(l <= r){
		res += (a[r]%k == 0);
		l++;
	}
	return res;
}

int32_t main(){
	cin >> n >> q >> k;
	for(int i = 0; i < n; i++){
		cin >> a[n];
	}
	int sz = ceil(sqrt(n));
	for(int i = 0, id = -1; i < sz; i++){
		if(i%sz == 0) id++;
		sqt[id][a[i]%k]++;
	}
	while(q--){
		int c; cin >> c;
		if(c == 1){ // qry
			int l, r; cin >> l >> r;
			cout << qrt(l, r) << endl;
		}else{ // upd
			int l, r, val; cin >> l >> r >> val;
			update(l, r, val);
		}
	}
}