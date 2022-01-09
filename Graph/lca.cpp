// https://codeforces.com/contest/208/problem/E
#include<bits/stdc++.h>
#define int long long
#define ff first
#define ss second
#define pb push_back
using namespace std;
typedef pair<int,int> pii;


// indexing of tree is from ( 0 to n - 1 ) ........
struct LCA{
    int n, H = 32, time = 0;
    vector<vector<int>> adj, parent;
    vector<int> depth;
    vector<int> startTime, endTime; // entry and exit time of nodes
    vector<int> storeLevel; // storeLevel[i] : level of ith node
    vector<vector<int>> level; // level[i] : store timings of all the node of ith level

    LCA(int _n = 0){ init(_n); }
    LCA(vector<vector<int>>& _adj){
        init(_adj.size());
        adj = _adj;
    } 

    void init(int sz){
        this -> n = sz;
        adj = vector<vector<int>>(n, vector<int>());
        parent = vector<vector<int>>(n, vector<int>(H, -1));
        depth = vector<int>(n, 0);
        startTime = vector<int>(n, 0);
        endTime = vector<int>(n, 0);
        storeLevel = vector<int>(n, 0);
        level = vector<vector<int>>(n);
    }

    void add_edge(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void dfs(int u, int p = -1, int lvl = 0){
        startTime[u] = ++time;
        storeLevel[u] = lvl;
        level[lvl].push_back(time);
        parent[u][0] = p;
        depth[u] = (p != -1 ? depth[p] + 1 : 0);
        for(int v : adj[u]){
            if(v == p) continue;
            dfs(v , u, lvl + 1);
        }
        endTime[u] = time;
    }

    void build(){
        for(int i = 0; i < n; i++){ // in case of forest 
            if(parent[i][0] == -1) dfs(i);
        }
        for(int i = 1; i < H; i++){
            for(int node = 0; node < n; node++){
                if(parent[node][i - 1] == -1) continue;
                parent[node][i] = parent[parent[node][i - 1]][i - 1];
            }
        }
    }

    int kth_ancestor(int u, int k){
        for(int i = H - 1; i >= 0 && u >= 0; i--){
            if(k & (1ll << i)) u = parent[u][i];
        }
        return u;
    }

    int lca(int u , int v){
        if(depth[u] > depth[v]) swap(u , v); // depth[u] < depth[v]
        v = kth_ancestor(v, depth[v] - depth[u]);
        if(u == v) return u;
        for(int i = H - 1; i >= 0 ; i--){
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