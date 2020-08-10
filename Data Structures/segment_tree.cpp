#include<bits/stdc++.h>
#define int long long
#define ff first
#define ss second
#define pb push_back
using namespace std;
/* 
Variables need to traverse on segment tree
1. si, ei of tree
2. node of segment tree
*/
struct SegmentTree{
	int n;
	vector<int> a, T;
	SegmentTree(vector<int> &a){
		this -> a = a;
		n = a.size();
		T.resize(4 * n, 0);
	}
	
	void build(int node, int si, int ei){
		if(si == ei){
			T[node] = a[si];
			return;
		}
		int mid = (si + ei)/2;
		build(2 * node, si, mid);
		build(2 * node + 1, mid + 1, ei);
		T[node] = min(T[2 * node], T[2 * node + 1]);
	}
	build() { build(1, 0, n - 1); }

	int qry(int l, int r, int node, int si, int ei){
		if(l > ei || r < si){
			return 1e9;
		}
		if(l <= si && r >= ei){
			return T[node];
		}
		int mid = (si + ei)/2;
		int L = qry(l, r, 2 * node, si, mid);
		int R = qry(l, r, 2 * node + 1, mid + 1, ei);
		return min(L, R);
	}
	int qry(int l, int r) { return qry(l, r, 1, 0, n - 1);}

	void update(int idx, int val, int node, int si, int ei){
		if(si == ei){
			T[node] = a[idx] = val;
			return;
		}
		int mid = (si + ei) / 2;
		if(idx <= mid){
			update(idx, val, 2 * node, si, mid);
		}else{
			update(idx,val, 2 * node + 1, mid + 1 , ei);
		}
		T[node] = min(T[2 * node], T[2 * node + 1]);
	}
	void update(int idx, int val){ update(idx, val, 1, 0, n - 1);}
};


int32_t main(){
	int n , q; cin >> n >> q;
	vector<int> a(n);
	for(int i = 0 ; i  <  n ;i++){
		cin >> a[i];
	}
	SegmentTree seg(a);
	seg.build();
	while(q--){
		char c; cin >> c;
		int l, r ; cin >> l >> r;
		if(c == 'u'){
			seg.update(l - 1, r);
		}else{
			cout << seg.qry(l - 1, r - 1) << endl;
		}
	}

}