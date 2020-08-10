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
	static int n;
	vector<int> a, T;
	SegmentTree(vector<int> a){
		this -> n = a.size();
		this -> a = a;
		this -> T.resize(4 * n, 0);
	}
	
	void build(int node = 1, int si = 0, int ei = n - 1){
		if(si == ei){
			T[node] = a[si];
			return;
		}
		int mid = (si + ei)/2;
		build(2 * node, si, mid);
		build(2 * node + 1, mid + 1, ei);
		T[node] = max(T[2*node] , T[2*node + 1]);
	} 

	int qry(int l, int r, int node = 1, int si = 0, int ei = n - 1){
		if(l > ei || r < si){
			return -1; 
		}
		if(l <= si && r >= ei){
			return T[node];
		}
		int mid = (si + ei)/2;
		int L = qry(l, r, 2 * node, si, mid);
		int R = qry(l, r, 2 * node + 1, mid + 1, ei);
		return max(L, R);
	}
	void update(int idx, int val, int node = 1, int si = 0, int ei = n - 1){
		if(si == ei){
			T[node] = val;
			a[idx] = val;
			return;
		}
		int mid = (si + ei)/2;
		if(idx <= mid){
			update(idx, val, 2 * node, si, mid);
		}else{
			update(idx, val, 2 * node + 1, mid + 1, ei);
		}
		T[node] = max(T[2 * node], T[2 * node + 1]);
	}
};


int32_t main(){
	

}