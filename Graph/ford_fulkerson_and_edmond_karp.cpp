// Ford Fulkersan
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

int MaxFlow(int S , int T){
	function<int(int, int)> bfs = [&](int S, int T){
		fill(parent.begin() , parent.end() , -1);
		parent[S] = -2;

		queue<pair<int,int>> q;
		q.push({S , 1e18});

		while(q.size() != 0){
			int u = q.front().ff;
			int f = q.front().ss;
			q.pop();
			for(auto v : adj[u]){
				if(parent[v] == -1 && capacity[u][v]){
					parent[v] = u;
					int new_f = min(f , capacity[u][v]);
					if(v == T) return new_f;
					q.push({v , new_f});
				}
			}
		}
		return 0ll;
	};
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
	cout << MaxFlow(S, T) << endl;
}