#include<bits/stdc++.h>
#define int long long
#define ff first
#define ss second
#define pb push_back
using namespace std;
typedef pair<int,int> pii;


// indexing of tree is from ( 0 to n - 1 ) ........
 

const int H = 32;
const int N = (int)2e5 + 5;
vector<int> adj[N];
int parent[N][H] , depth[N];

// dfs used to set parent of a node, depth of a node, subtree size of a node
void dfs(int u , int par = -1){
	if(par != -1){ 
		parent[u][0] = par; // just usse 1 height uppar walla
		depth[u] = depth[par] + 1;
	}
	for(auto v : adj[u]){
		if(v == par) continue;
		dfs(v , u);
	}
}

// precompute all parent of all node which present at height of 2^i
// if 2^i th parent is not reachable then place -1
 
void lca_pre(int n){
	for(int i = 1; i < H ; i++){
		for(int node = 0 ; node < n ; node++){
			if(parent[node][i - 1] == -1) continue;
			parent[node][i] = parent[parent[node][i - 1]][i - 1];
		}
	}
}


// to get lca of two node u and v
 
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
	// now we are just one hoop below the lca
	return parent[u][0];
}
int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int n, m ; cin >> n >> m;
	for(int i =0 ; i  < n -1 ; i++){
		int s ,d ; cin >> s >> d;
		adj[s - 1].pb(d - 1);
		adj[d - 1].pb(s - 1);
	}
	memset(parent , -1 , sizeof(parent));
	dfs(0);
	lca_pre(n);
	

}