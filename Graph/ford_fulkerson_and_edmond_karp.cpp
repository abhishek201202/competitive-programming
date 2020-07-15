#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
using namespace std;

const int N = 1e5;
vector<vector<int>> adj , capacity;
vector<int> parent(N , 0);
int n , m;

int bfs(int S , int T){
	fill(parent.begin() , parent.end() , -1);
	parent[S] = -2;

	queue<pair<int,int>> q;
	q.push({S , 1e18});

	while(q.size() != 0){
		pair<int,int> curr = q.front();
		int u = curr.ff;
		int f = curr.ss;
		for(int i = 0 ;i < adj[u].size() ; i++){
			int v = adj[u][i];
			if(parent[v] == -1 && capacity[u][v]){
				parent[v] = u;
				int new_f = min(f , capacity[u][v]);
				if(v == T) return new_f;
				q.push({v , new_f});
			}
		}
	}
	return 0;
}



int ford_fulkerson(int S , int T){
	int flow = 0;
	while(1){
		int curr_flow = bfs(S , T);
		if(!curr_flow) break;
		flow += curr_flow;
		int curr = T;
		while(curr != S){
			int prev = parent[curr];
			capacity[prev][curr] -= curr_flow;
			capacity[curr][prev] += curr_flow;
			curr = prev;
		}
	}
	return flow;
}


int32_t main(){
	adj.resize(N , vector<int>());
	capacity.resize(N , vector<int>(N , 0));

	cin >> n >> m;
	for(int i = 0 ;i < m; i ++){
		int s , d , c; cin >> s >> d >> c;
		adj[s - 1].pb(d - 1);
		adj[d - 1].pb(s - 1);

		capacity[s - 1][d - 1] = c;
		capacity[d - 1][s - 1] = -c;

	}
	int S , T;
	cin >> S >> T;

}