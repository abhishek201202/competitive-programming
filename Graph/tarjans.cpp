// finding bridge in a graph
#include<bits/stdc++.h>
#define int long long
#define ff first
#define ss second
#define pb push_back
using namespace std;

const int N = 1e5;
vector<int> adj[N];
vector<int> in , min_time , vis;
vector<pair<int,int>> bridge;
int n , m ;
int timer;

void dfs(int u , int p = -1){
	in[u] = timer++;
	vis[u] = 1;
	for(auto v : adj[u]){
		if(v == p) continue;
		
		min_time[u] = min(min_time[u] , min_time[v]);
		if(vis[v]) continue;
		
		dfs(v , u);
		min_time[u] = min(min_time[u] , min_time[v]);
	}
	for(auto v : adj[u]){
		if(v == p) continue;
		min_time[u] = min(min_time[u] , in[v]);
	}

	if(p != -1 && min_time[u] > in[p]){
		bridge.pb({p , u});
	}
}

void tarjans(){
	timer = 0;
	in.resize(n , 0);
	vis.resize(n , 0);
	min_time.resize(n , 1e8);
	for(int i = 0 ;i < n ; i++){
		if(!vis[i]) dfs(i);
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