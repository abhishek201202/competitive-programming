#include<bits/stdc++.h>
#define int long long
#define ff first
#define ss second
#define pb push_back
#define ALL(x) x.begin() , x.end()
using namespace std;

struct Edge{
	int from , to , cap , f;
};

struct Dinic{
	int N ;
	vector<Edge> E;
	vector<vector<int>> adj;
	vector<int> dis , par;

	Dinic(int N) : N(N) , E(0) , adj(N) , dis(N) , par(N){}

	void add_edge(int from , int to , int c){
		if(from == to) return;
		adj[from].pb(E.size());
		E.pb({from , to , c , 0});
		
		adj[to].pb(E.size());
		E.pb({to , from , 0 , 0});
	}
	bool BFS(int s ,int t){
		queue<int> q;
		q.push(s);
		fill(ALL(dis) , N + 1);
		dis[s] = 0;
		while(q.size() != 0){
			int u = q.front(); q.pop();
			if(u == t) break;
			for(auto id : adj[u]){
				Edge &curr = E[id];
				int u = curr.from;
				int v = curr.to;
				if(curr.cap - curr.f > 0 && dis[u] + 1 < dis[v]){
					dis[v] = dis[u] + 1;
					q.push(v);
				}
			}
		}
		return dis[t] != N + 1;
	}
	int DFS(int u , int t , int flow = -1){
		if(u == t || flow == 0) return flow;
		for(int &i = par[u]; i < adj[u].size() ; i++){
			Edge & e = E[adj[u][i]];
			Edge & oe = E[adj[u][i] ^ 1];
			if(dis[e.to] == dis[e.from] + 1){
				int amt = e.cap - e.f;
				if(flow != -1 && amt > flow) amt = flow;
				if(int pushed = DFS(e.to , t , amt)){
					e.f += pushed;
					oe.f -= pushed;
					return pushed;
				}
			}
		}
		return 0;
	}	

	int find_max_flow(int s , int t){
		int res = 0;
		while(BFS(s , t)){
			fill(ALL(par) , 0);
			while(int flow = DFS(s , t)) res += flow;
		}
		return res;
	}

};

int32_t main(){
	int n , m ; cin >> n >> m;
	Dinic algo(n);
	for(int i = 0 ; i < m ; i++){
		int u ,v ,c; cin >> u >> v >> c;
		algo.add_edge(u - 1 , v - 1 , c);
		algo.add_edge(v - 1 , u - 1 , c);
	}
	cout << algo.find_max_flow(0 , n - 1) << endl;

}