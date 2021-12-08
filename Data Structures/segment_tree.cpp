#include<bits/stdc++.h>
#define int long long
#define ff first
#define ss second
#define pb push_back
using namespace std;


/* 
Variables need to traverse on segment tree
1. si, ei of tree
2. root of segment tree
*/

struct Node{
    int mx; // for max range query (variables according to the problem)
    Node(){
        mx = -1e18; // always initialize with the value which you want to return for boundry cases
    }
    void update(int val){ // node update
        mx = val;
    }
    Node operator+(const Node &v) const{ // node merge 
        Node res;
        res.mx = max(mx, v.mx);
        return res;
    }
};

struct SegmentTree{
    int n;
    vector<int> a;
    vector<Node> T;

    SegmentTree(vector<int> &a){
        this -> a = a;
        n = a.size();
        T.resize(4 * n);
    }
    
    void build(int root, int si, int ei){
        if(si == ei){
            T[root].mx = a[si];
            return;
        }
        int mid = (si + ei)/2;
        build(2 * root, si, mid);
        build(2 * root + 1, mid + 1, ei);
        T[root] = T[2 * root] + T[2 * root + 1];
    }
    void build() { build(1, 0, n - 1); }

    Node qry(int l, int r, int root, int si, int ei){
        if(l > ei || r < si){
            return Node();
        }
        if(l <= si && r >= ei){
            return T[root];
        }
        int mid = (si + ei)/2;
        Node L = qry(l, r, 2 * root, si, mid);
        Node R = qry(l, r, 2 * root + 1, mid + 1, ei);
        return L + R;
    }
    int qry(int l, int r) { return qry(l, r, 1, 0, n - 1).mx;}

    void update(int idx, int val, int root, int si, int ei){
        if(si == ei){
            T[root].update(val);
            return;
        }
        int mid = (si + ei) / 2;
        if(idx <= mid){
            update(idx, val, 2 * root, si, mid);
        }else{
            update(idx,val, 2 * root + 1, mid + 1 , ei);
        }
        T[root] = T[2 * root] + T[2 * root + 1];
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