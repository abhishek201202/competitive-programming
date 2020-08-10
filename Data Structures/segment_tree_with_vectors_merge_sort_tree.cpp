#include<bits/stdc++.h>
#define int long long
#define ff first
#define ss second
#define pb push_back
#define ALL(x) x.begin(), x.end()
using namespace std;

// KQuery ===> Online Queries
struct SegmentTree{
	vector<vector<int>> Tree;
	vector<int> a;
	int n;
	SegmentTree(vector<int> &a){
		this -> a = a;
		n = a.size();
		Tree.resize(4 * n, vector<int>());
	}
	
	void build(int node, int si, int ei){
		if(si == ei){
			Tree[node].push_back(a[si]);
			return;
		}
		int mid = (si + ei)/2;
		build(2 * node, si, mid);
		build(2 * node + 1, mid + 1, ei);
		merge(ALL(Tree[2 * node]), ALL(Tree[2 * node + 1]), back_inserter(Tree[node]));
	}
	void build() { build(1, 0, n - 1); }

	int qry(int l, int r, int k, int node, int si, int ei){
		if(l > ei || r < si){
			return 0;
		}
		if(l <= si && r >= ei){
			return Tree[node].size() - (upper_bound(ALL(Tree[node]), k) - Tree[node].begin());
		}
		int mid = (si + ei)/2;
		int L = qry(l, r, k, 2 * node, si, mid);
		int R = qry(l, r, k, 2 * node + 1, mid + 1, ei);
		return L + R;
	}
	int qry(int l, int r, int k) { return qry(l, r, k, 1, 0, n - 1);}
};
 
int32_t main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int n; cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	SegmentTree seg(a);
	seg.build();

	int q; cin >> q;
	while(q--){
		int l, r, k; cin >> l >> r >> k;
		cout << seg.qry(l - 1, r - 1, k) << endl;
	}
}