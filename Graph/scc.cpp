// strongly connected component
// kosaraju algorithm
#include<bits/stdc++.h>
#define int long long
#define ff first
#define ss second
#define pb push_back
using namespace std;

const int N = 1e5 + 500;
vector<int> adj[N] , adjT[N];
vector<vector<int>> component;
stack<int> finishV;
vector<int> vis(N);
int n , m , sz;

void dfs(int u , int p = -1){
	vis[u] = 1;
	for(auto v : adj[u]){
		if(v == p) continue;
		if(vis[v]) continue;
		dfs(v , u);
	}
	finishV.push(u);
}

void dfs_collect(int u , int p = -1){
	vis[u] = 1;
	component[sz].pb(u);
	for(auto v : adjT[u]){
		if(v == p) continue;
		if(vis[v]) continue;
		dfs_collect(v , u);
	}
}
void kosaraju(){
	sz = 0;
	component.resize(0);
	fill(vis.begin() , vis.end() , 0);
	for(int i = 0 ;i < n ;i++){
		if(!vis[i]) dfs(i);
	}

	fill(vis.begin() , vis.end() , 0);
	while(finishV.size() != 0){
		int curr = finishV.top();
		finishV.pop();
		if(vis[curr]) continue;
		component.pb(vector<int>());
		dfs_collect(curr);
		sz++;
	}
}

int32_t main(){
	cin >> n >> m;
	for(int i = 0; i < m ;i++){
		int x , y; cin >> x >> y;
		adj[x - 1].pb(y - 1);
		adjT[y - 1].pb(x - 1);
	}
	kosaraju(); 
	int ans = 0;
	for(int i = 0; i < component.size() ; i++){
		for(int j = 0 ; j < component[i].size() ; j++){
			cout << component[i][j] + 1 << " ";
		}
		cout << endl;
	}
	cout << ans << endl;
}
/*
7 5
1 2
2 3
3 1
4 5
6 7
*/