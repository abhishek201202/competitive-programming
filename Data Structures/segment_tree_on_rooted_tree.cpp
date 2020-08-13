#include<bits/stdc++.h>
#define int long long
#define ff first
#define ss second
using namespace std;

const int N = 1e5 + 5;
int n, st[N], et[N];
vector<int> adj[N];

vector<int> Euler_tour(){
	vector<int> vis(n, 0);
	vector<int> order;
	function<int(int)> dfs = [&](int u){
		vis[u] = 1;
		order.push_back(u);
		for(auto v : adj[u]){
			if(vis[v]) continue;
			order.push_back(dfs(v));
		}
		return u;
	};
	order.push_back(dfs(0));
	memset(st, -1, sizeof st);
	memset(et, -1, sizeof et);
	for(int i = 0; i < order.size(); i++){
		if(st[order[i]] == -1){
			st[order[i]] = i;
		}else{
			et[order[i]] = i;
		}
	}
	return order;
} 


class Segment_tree{
public:
	int sz;
	vector<int> a, tree;
	Segment_tree(vector<int> &a){
		this -> a = a;
		this -> sz = a.size();
		tree.resize(4 * sz, 0);
	}

	void build(int node, int l, int r){
		if(l == r){
			tree[node] = a[l];
			return;
		}
		int mid = (l + r) / 2;
		build(2 * node, l, mid);
		build(2 * node + 1, mid + 1, r);
		tree[node] = tree[2 * node] + tree[2 * node + 1];
	}
	void update(int idx, int val, int node, int l, int r){
		if(l == r){
			tree[idx] = val;
			return;
		}
		int mid = (l + r) / 2;
		if(idx <= mid){
			update(idx, val, 2 * node, l, mid);
		}else{
			update(idx, val, 2 * node + 1, mid + 1, r);
		}
	}
	int qry(int l, int r, int node, int si, int ei){
		if(r < si || l > ei) return 0;
		if(l <= si && r >= ei) return tree[node];
		int mid = (l + r) / 2;
		int L = qry(l, r, 2 * node, si, mid);
		int R = qry(l, r, 2 * node + 1, mid + 1, ei);
		return L + R;
	}
};

int32_t main(){
	cin >> n;
	for(int i = 0; i < n - 1; i++){
		int x, y; cin >> x >> y;
		adj[x - 1].push_back(y - 1);
	}
	vector<int> order = Euler_tour();
	Segment_tree seg(order);
	
	int q; cin >> q;
	while(q--){
		int x; cin >> x;
		if(x == 1){ // update on node
			int node, val; cin >> node >> val;
			int fidx = st[node - 1];
			int lidx = et[node - 1];
			seg.update(fidx, val, 1, 0, n - 1);
			seg.update(lidx, val, 1, 0, n - 1);
		}else{ // query on subtree
			int node; cin >> node;
			int fidx = st[node - 1];
			int lidx = et[node - 1];
			cout << seg.qry(fidx, lidx, node, 0, n - 1) << endl;
		}
	}
}