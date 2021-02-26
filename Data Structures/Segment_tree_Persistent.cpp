// Tested on :: https://www.spoj.com/problems/KQUERY/
#include<bits/stdc++.h>
using namespace std;

const int N = 5e6 + 5;
const int LOGN = 32;

namespace PathCopySegmentTree{
	struct info{
		int sum;
		info() : sum(0){}
	} Tree[N]; // 1 based indexing

	int n, sz = 0, V = 1; 
	int Left[N], Right[N], Root[N];

	// return the idx of root
	// Don't Forget to update the value of Root array
	int update(int idx, int val, int node, int si, int ei){
		if(idx < si || idx > ei) return node;
		if(si == ei){
			Tree[++sz].sum = Tree[node].sum + val;
			return sz;
		}
		int P = ++sz, mid = (si + ei) / 2;
		Left[P] = update(idx, val, Left[node], si, mid);
		Right[P] = update(idx, val, Right[node], mid + 1, ei);
		Tree[P].sum = Tree[Left[P]].sum + Tree[Right[P]].sum;
		return P;
	}

	void build(vector<int>& a){
		n = a.size();
		Root[0] = 0; // 0th version is just a empty segtree
		for(int i = 0; i < n; i++){
			Root[V] = update(a[i], 1, Root[V - 1], 1, 1e9);
			V++;
		}
	}

	int qry(int l, int r, int node, int si, int ei){
		if(l > ei || r < si) return 0;
		if(l <= si && r >= ei) return Tree[node].sum;
		int mid = (si + ei) / 2;
		int L = qry(l, r, Left[node], si, mid);
		int R = qry(l, r, Right[node], mid + 1, ei);
		return L + R;
	}
	int qry(int l, int r, int k){
		int res = qry(k + 1, 1e9, Root[r + 1], 1, 1e9);
		res -= qry(k + 1, 1e9, Root[l - 1 + 1], 1, 1e9);
		return res;
	}
}

namespace FatNodeSegmentTree{
	struct info{
		int sum, ver;
		info() : sum(0) {}
	}Tree[N];
	int n, sz = 0, V = 1; 
	int Left[N], Right[N], Root[N];
}



int32_t main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int n; cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	PathCopySegmentTree::build(a);
	int q; cin >> q;
	for(int i = 0; i < q; i++){
		int l, r, k; cin >> l >> r >> k;
		l--, r--;
		cout << PathCopySegmentTree::qry(l, r, k) << endl;
	}
}