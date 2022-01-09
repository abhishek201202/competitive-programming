#include<bits/stdc++.h>
#define int long long
#define ff first
#define ss second
#define pb push_back
using namespace std;
typedef pair<int,int> pii;


// indexing of tree is from ( 0 to n - 1 ) ........
struct LCA{
	int n, H = 32;
	vector<vector<int>> adj, parent;
	vector<int> depth;

	LCA(int _n = 0){ init(_n); }
	LCA(vector<vector<int>>& _adj){
		init(_adj.size());
		adj = _adj;
	} 

	void init(int sz){
		this -> n = sz;
		adj = vector<vector<int>>(sz, vector<int>());
		parent = vector<vector<int>>(sz, vector<int>(H, 0));
		depth = vector<int>(sz, 0);
	}

	void add_edge(int u, int v){
		adj[u].push_back(v);
		adj[v].push_back(u);
	}


	void build(){
		function<void(int, int)> dfs = [&](int u, int par = -1){
			if(par != -1){ 
				parent[u][0] = par;
				depth[u] = depth[par] + 1;
			}
			for(auto v : adj[u]){
				if(v == par) continue;
				dfs(v , u);
			}
		};
		dfs(0, -1);
		for(int i = 1; i < H ; i++){
			for(int node = 0; node < n; node++){
				if(parent[node][i - 1] == -1) continue;
				parent[node][i] = parent[parent[node][i - 1]][i - 1];
			}
		}
	}

	int lca(int u , int v){
		if(depth[u] > depth[v]) swap(u , v);
		int diff = depth[v] - depth[u];
		for(int i = 0 ; i < H ; i++){
			if((diff >> i) & 1) v = parent[v][i];
		}
		if(u == v) return u;
		for(int i = H - 1 ; i >= 0 ; i--){
			if(parent[u][i] == -1 || parent[v][i] == -1) continue;
			if(parent[u][i] != parent[v][i]){
				u = parent[u][i];
				v = parent[v][i];
			}
		}
		return parent[u][0];
	}
};


int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int n, m ; cin >> n >> m;
	LCA lca(n);
	for(int i = 0; i  < n - 1; i++){
		int s ,d ; cin >> s >> d;
		lca.add_edge(s - 1, d - 1);
	}
	lca.build();

}