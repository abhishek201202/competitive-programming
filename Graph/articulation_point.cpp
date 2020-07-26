// finding Articulation Point in a graph
#include<bits/stdc++.h>
#define int long long
#define ff first
#define ss second
#define pb push_back
using namespace std;

const int N = 1e5;
int n, m, timer, tin[N], low[N], vis[N], AP[N];
vector<int> adj[N];

void tarjans(){
	timer = 0;
	memset(tin, 0, sizeof timer);
	memset(low, 0, sizeof low);
	memset(vis, 0, sizeof vis);
	memset(AP, 0, sizeof AP);
	function<void(int, int)> dfs = [&](int u, int p){
		vis[u] = 1;
		tin[u] = low[u] = timer++;
		int children = 0;
		for(auto v : adj[u]){
			if(v == p) continue;
			if(vis[v]){
				low[u] = min(low[u], tin[v]);
			}else{
				dfs(v, u);
				if(low[v] >= tin[u] && p != -1){
					AP[u] = 1;
				}
				low[u] = min(low[u], low[v]);
			}
		}
		if(p == -1 && children > 1) AP[u] = 1;
	};
	for(int i = 0 ;i < n ; i++){
		if(!vis[i]) dfs(i, -1);
	}
}

int32_t main(){
	int tt; cin >> tt;
	while(tt--){
		for(int i = 0; i < N; i++){
			adj[i].clear();
		}
		cin >> n >> m;
		for(int i = 0 ;i < m ; i++){
			int x , y ; cin >> x >> y;
			adj[x - 1].pb(y - 1);
			adj[y - 1].pb(x - 1);
		}
		tarjans();
		int res = 0;
		for(int i = 0; i < n; i++){
			res += AP[i];
		}
		cout << res << endl;
	}
}	