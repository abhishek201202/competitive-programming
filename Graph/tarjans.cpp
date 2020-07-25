// finding bridge in a graph
#include<bits/stdc++.h>
#define int long long
#define ff first
#define ss second
#define pb push_back
using namespace std;

const int N = 1e5;
int n, m, timer, tin[N], low[N], vis[N];
vector<int> adj[N];
vector<pair<int,int>> bridge;

void tarjans(){
	timer = 0;
	memset(tin, 0, sizeof timer);
	memset(low, 0, sizeof low);
	memset(vis, 0, sizeof vis);
	bridge.clear();
	function<void(int, int)> dfs = [&](int u, int p){
		vis[u] = 1;
		tin[u] = low[u] = timer++;
		for(auto v : adj[u]){
			if(v == p) continue;
			if(vis[v]){
				low[u] = min(low[u], tin[v]);
			}else{
				dfs(v, u);
				low[u] = min(low[u], low[v]);
				if(low[v] > tin[u]){
					bridge.push_back({u, v});
				}
			}
		}
	};
	for(int i = 0 ;i < n ; i++){
		if(!vis[i]) dfs(i, -1);
	}
}

int32_t main(){
	cin >> n >> m;
	for(int i = 0 ;i < m ; i++){
		int x , y ; cin >> x >> y;
		adj[x - 1].pb(y - 1);
		adj[y - 1].pb(x - 1);
	}
	tarjans();
	for(int i = 0; i < bridge.size() ; i++){
		cout << bridge[i].ff + 1 << " " << bridge[i].ss + 1 << endl;
	}
}	

/*
15 21
1 2
1 3 
2 3
2 4
2 6
3 5
3 7
3 8
4 5
5 6
6 7
8 9
8 10
9 10
9 12
10 11
11 12
12 13
13 14
13 15
14 15
output : (12 , 13) , (3 , 8)
*/
/*
5 6
1 2 
1 3
2 3
2 4
3 5
4 5
output : no bridge is present
*/