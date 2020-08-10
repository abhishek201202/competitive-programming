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
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
struct SegmentTree{
	int n;
	vector<int> a, T, o, c;
	SegmentTree(vector<int> &a){
		this -> a = a;
		n = a.size();
		T.resize(4 * n, 0);
		o.resize(4 * n, 0);
		c.resize(4 * n, 0);
	}
	
	void build(int node, int si, int ei){
		if(si == ei){
			if(a[si] == 1){
				o[node] = 1;
			}else{
				c[node] = 1;
			}
			return;
		}
		int mid = (si + ei)/2;
		build(2 * node, si, mid);
		build(2 * node + 1, mid + 1, ei);
		int mn = min(o[2 * node], c[2 * node + 1]);
		T[node] = T[2 * node] + T[2 * node + 1] + mn;
		o[node] = o[2 * node] + o[2 * node + 1] - mn;
		c[node] = c[2 * node] + c[2 * node + 1] - mn;
	}
	build() { build(1, 0, n - 1); }

	piii qry(int l, int r, int node, int si, int ei){
		if(l > ei || r < si){
			return {0, {0, 0}};
		}
		if(l <= si && r >= ei){
			return {T[node], {o[node], c[node]}};
		}
		int mid = (si + ei)/2;
		piii L = qry(l, r, 2 * node, si, mid);
		piii R = qry(l, r, 2 * node + 1, mid + 1, ei);
		piii res({0, {0, 0}});
		int mn = min(L.second.first, R.second.second);
		res.first = L.first + R.first + mn;
		res.second.first = L.second.first + R.second.first - mn;
		res.second.second = L.second.second + R.second.second - mn;
		return res;
	}
	int qry(int l, int r) { return qry(l, r, 1, 0, n - 1).first;}
};


int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	string s; cin >> s;
	vector<int> a;
	for(int i = 0; i < (int)s.size(); i++){
		if(s[i] == '(') a.push_back(1);
		else a.push_back(-1);
	}
	SegmentTree seg(a);
	seg.build();
	int q; cin >> q;
	while(q--){
		int l, r; cin >> l >> r;
		cout << 2 * seg.qry(l - 1, r - 1) << endl;
	}
}