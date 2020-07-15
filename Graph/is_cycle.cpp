#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
using namespace std;

const int N = 1e5;
vector<int> adj[N];
vector<pair<int,int>> cycle;
int col[N] , parent[N];
int n , m;


// 0 ==>> unvisited
// 1 ==>> visited and removed from the stack yet
// 2 ==>> visited and removed from the stack

// for undirected graph it wll give same cycle more than once 
// for directed graph
void dfs(int u , int p = -1){
	col[u] = 1;
	parent[u] = p;
	for(int i = 0 ;i < adj[u].size() ;i++){
		int v = adj[u][i];
		if(col[v] == 1){
			cycle.pb({v , u}); // start and end vertex of cycle 
			continue;
		}
		dfs(v , u);
	}
	col[u] = 2;
}


int32_t main(){
	cin >> n >> m;
	for(int i = 0 ; i < m;  i++){
		int x , y; cin >> x >> y;
		adj[x - 1].pb(y - 1);
		// adj[y - 1].pb(x - 1);
	}
	dfs(0);
	for(int i = 0 ; i < cycle.size() ; i++){
		cout << cycle[i].ff << " " << cycle[i].ss << endl;
	}
}
/*
5 6
1 2
2 5
5 1
2 3
3 4
4 2
*/
/*
5 6
1 2
2 5
1 5
2 3
3 4
4 2
*/