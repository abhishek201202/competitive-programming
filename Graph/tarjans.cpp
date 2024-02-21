// finding Articulation Point && Bridges in a graph
#include<bits/stdc++.h>
#define int long long
#define ff first
#define ss second
#define pb push_back
using namespace std;

const int N = 1e5;
int n, m, timer, tin[N], low[N], vis[N], AP[N];
vector<int> adj[N];
vector<pair<int, int>> B;

void tarjans(){
	timer = 0;
	memset(tin, 0, sizeof timer); // starting time of each node
	memset(low, 0, sizeof low); // minimum borrower time of all adjacent nodes, except parent
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
				low[u] = min(low[u], low[v]);
				// For Bridges
				if(low[v] > tin[u]){
					B.push_back({u, v});
				}
				// For Articulation point
				children++;
				if(low[v] >= tin[u] && p != -1){
					AP[u] = 1;
				}
			}
		}
		if(p == -1 && children > 1) AP[u] = 1;
	};
	for(int i = 0 ;i < n ; i++){
		if(!vis[i]) dfs(i, -1);
	}
}

int32_t main(){
	int tt = 1;
	// cin >> tt;
	while(tt--){
		for(int i = 0; i < N; i++){
			adj[i].clear();
		}
		cin >> n >> m;
		for(int i = 0 ;i < m ; i++){
			int x , y ; cin >> x >> y;
			adj[x].pb(y);
			adj[y].pb(x);
		}
		tarjans();
		int AP_cnt = 0;
		for(int i = 0; i < n; i++){ 
			AP_cnt += AP[i];
		}
		cout << AP_cnt << endl;
		for(int i = 0; i < n; i++){
			if(AP[i]){
				cout << i << " "; 
			}
		}
		cout << endl << B.size() << endl;
		for(int i = 0; i < B.size(); i++){
			if(B[i].ff > B[i].ss) swap(B[i].ff, B[i].ss);
		}
		sort(B.begin(), B.end(), [&](pair<int, int> &a, pair<int, int> &b){
			if(a.ff == b.ff){
				return a.ss < b.ss;
			}else{
				return a.ff < b.ff;
			}
		});
		for(int i = 0; i < B.size(); i++){
			cout << B[i].ff << " " << B[i].ss << endl;
		}
	}
}	
