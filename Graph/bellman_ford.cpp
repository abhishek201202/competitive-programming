#include<bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
#define int long long
#define pii pair<int,int>
using namespace std;

const int N = 1e5;
vector<int> adj[N] , weight[N];
int dis[N];
int n , m ;

// single source shortest path
// applicable for -ve weighted graph as well
// return weather it contain a negative cycle or not....[1 -> Yes]....[0 -> No]
bool bellman_ford(int s){
	for(int i = 0 ; i < n ; i++) dis[i] = 1e8;
	dis[s] = 0;
	for(int k = 0; k < n; k++){
		bool any_change = false;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < adj[i].size(); j++){
				int u = i, v = adj[u][j];
				int w = weight[u][j];
				if(dis[v] > dis[u] + w){
					any_change = true;
					dis[v] = dis[u] + w;
				}
			}
		}
		if(k == n - 1 && any_change) return true;
	}
	return false;
}


int32_t main(){
	int tt; cin >> tt;
	while(tt--){
		for(int i = 0; i < N; i++){
			adj[i].clear();
			weight[i].clear();
		}
		cin >> n >> m;
		for(int i = 0 ; i < m ; i++){
			int x, y , w; cin >> x >> y >> w;
			adj[x].pb(y);
			weight[x].pb(w);
		}
		cout << bellman_ford(0) << endl;
	}	
}