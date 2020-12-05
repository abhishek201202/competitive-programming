#include<bits/stdc++.h>
#define int long long 
#define ff first
#define ss second
using namespace std;
 
struct info{
	int one, zero;
	info(){
		one = zero = 0;
	}
	info(int a, int b){
		one = a;
		zero = b;
	}
};
 
struct SEG{
	int n;
	vector<info> a, tree;
	vector<int> lazy;
	SEG(){}
	void init(vector<info> a){
		this -> a = a;
		n = a.size();
		tree.resize(4 * n);
		lazy.resize(4 * n);
	}
 
	void bld(int node, int si, int ei){
		if(si == ei){
			tree[node] = a[si];
			return;
		}
		int mid = (si + ei) / 2;
		bld(2 * node, si, mid);
		bld(2 * node + 1, mid + 1, ei);
		tree[node].one = tree[2 * node].one + tree[2 * node + 1].one;
		tree[node].zero = tree[2 * node].zero + tree[2 * node + 1].zero;
 	}
 	void bld(){
 		bld(1, 0, n - 1);
 	}
 
 	void push(int si, int ei, int node){
 		if(lazy[node]){
 			if(lazy[node]&1)
 				swap(tree[node].one, tree[node].zero);
 			if(si != ei){
 				lazy[2 * node] += lazy[node];
 				lazy[2 * node + 1] += lazy[node];
 			}
 			lazy[node] = 0;
 		}
 	}
 
 	void up(int l, int r, int node, int si, int ei){
 		push(si, ei, node);
 		if(l > ei || r < si) return;
 		if(l <= si && r >= ei){
 			swap(tree[node].one, tree[node].zero);
 			if(si != ei){
 				lazy[2 * node] += lazy[node] + 1;
 				lazy[2 * node + 1] += lazy[node] + 1;
 			}
			return;
 		}
 		int mid = (si + ei) / 2;
 		up(l, r, 2 * node, si, mid);
 		up(l, r, 2 * node + 1, mid + 1, ei);
 		tree[node].one = tree[2 * node].one + tree[2 * node + 1].one;
 		tree[node].zero = tree[2 * node].zero + tree[2 * node + 1].zero;
 	}
 	void up(int l, int r){
 		up(l, r, 1, 0, n - 1);
 	}
 
 	info qry(int l, int r, int node, int si, int ei){
 		if(l > ei || r < si) return {0, 0};
 		push(si, ei, node);
 		if(l <= si && r >= ei){
 			return tree[node];
 		}
 		int mid = (si + ei) / 2;
 		info L = qry(l, r, 2 * node, si, mid);
 		info R = qry(l, r, 2 * node + 1, mid + 1, ei);
 		info res({L.one + R.one, L.zero + R.zero});
 		return res;
 	}
 
 	int qry(int l, int r){
 		info res = qry(l, r, 1, 0, n - 1);
 		return res.one;
 	}
};
 
 
int32_t main(){
	int n; cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}	
 
	vector<SEG> seg(20);
	for(int bit = 0; bit < 20; bit++){
		vector<info> temp(n);
		for(int i = 0; i < n; i++){
			if(a[i]&(1ll << bit)){
				temp[i].one++;
			}else{
				temp[i].zero++;
			}
		}
		seg[bit].init(temp);
		seg[bit].bld();
	}
 
	int q; cin >> q;
	while(q--){
		int c; cin >> c;
		if(c == 1){
			int l, r; cin >> l >> r;
			l -- , r --;
			int res = 0;
			for(int bit = 0; bit < 20; bit++){
				int cnt = seg[bit].qry(l, r);
				res += cnt * (1ll << bit);
			}
			cout << res << endl;
		}else{
			int l, r, x; cin >> l >> r >> x;
			l -- , r --;
			for(int i = 0 ; i < 20; i++){
				if(x & (1ll << i)){
					seg[i].up(l, r);
				}
			}
		}
	}
}