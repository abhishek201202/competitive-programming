#include<bits/stdc++.h>
#define int long long
#define ff first
#define ss second
#define pb push_back
using namespace std;
// tested on [https://codeforces.com/group/FLVn1Sc504/contest/274509/problem/T]


struct Edge{
	int from , to , cap , f;
};

struct Maxflow{
	int n , s , t; // no of vertex , source , sink
	vector<Edge> edge;
	vector<vector<int>> adj , height_ver; // ith height pe konse konse vertex present hai
	vector<int> height , excess;

	void init(int n , int s , int t){
		this -> n = n; this -> s = s; this -> t = t;
		adj.resize(n , vector<int>());
		height_ver.resize(2 * n + 1 , vector<int>());
		height.resize(n , 0);
		excess.resize(n , 0);
	}

	void add_edge(int from , int to , int cap){
		if(from == to) return ;
		// adj is used to store the edge no -> useful during dfs or bfs
		// (0 , 1) , (2 , 3) , (4 , 5) .... so on
		// this all above pair are showing the edge no of (from , to) pair
		// (0 , 1) === >>> (id , id ^ 1)
		adj[from].pb(edge.size());  
		edge.pb({from , to , cap , 0});

		adj[to].pb(edge.size());
		edge.pb({to , from , 0 , 0});
	}

	void push(int id){
		int u = edge[id].from , v = edge[id].to;
		int excess_at_u = excess[u];
		int curr_cap = edge[id].cap;
		int curr_flow = edge[id].f;
		int curr_residual_cap_of_preflow = curr_cap - curr_flow;
		// amount_of_flow_to_this_edge
		int amount = min(excess_at_u , curr_residual_cap_of_preflow);

		if(v != s && v != t && !excess[v] && amount){
			height_ver[height[v]].pb(v);
		}

		edge[id].f += amount;
		edge[id^1].f -= amount;

		excess[u] -= amount;
		excess[v] += amount;
	}

	int relabel(int u){
		height[u] = 2 * n; // maximum height which u can get
		for(auto id : adj[u]){
			int v = edge[id].to;
			if(edge[id].cap - edge[id].f > 0){
				height[u] = min(height[u] , height[v] + 1);
			}
		}
		height_ver[height[u]].pb(u);
		return height[u];
	}


	int find_max_flow(){
		// initialize height and preflow
		height[s] = n;
		for(auto id : adj[s]){
			// initially there is no flow , therefore no outgoing flow will be there
			excess[s] += edge[id].cap - 0;
			// push all the water to this edge with edge no = id
			push(id);
		}

		// pick a node with excess > 0 and maximum height 
		// until not get a flow in the network
		int H = 0;
		while(H >= 0){
			if(height_ver[H].size() == 0) break;
			int u = height_ver[H].back();
			height_ver[H].pop_back();
			while(excess[u]){
				for(int i = 0 ; i < adj[u].size() && excess[u] ; i++){
					int id = adj[u][i];
					Edge curr = edge[id];
					int v = curr.to;
					if(curr.cap - curr.f > 0 && height[u] == height[v] + 1){
						push(id);
					}
				}
				if(excess[u]) H = relabel(u);
			}
			while(H >= 0 && !height_ver[H].size()) H--;
		}

		// cal final maximum flow 
		int ans = 0;
		for(auto id : adj[s]){
			ans += edge[id].f;
		}

		return ans;
	}


};



int32_t main(){
	int n; cin >> n;
	map<char , int> mp;
	vector<pair<pair<int,int> , int>> v;
	int cnt = 0;
	for(int i = 0 ; i < n ; i++){
		char x , y;
		int c; cin >> x >> y >> c; 
		if(!mp.count(x)){
			mp[x] = cnt++;
		}
		if(!mp.count(y)){
			mp[y] = cnt++;
		}
		v.pb({{mp[x] , mp[y]} , c});
	}
	Maxflow algo;
	algo.init(cnt , mp['A'] , mp['Z']);
	for(int i = 0 ; i < n ; i++){
		algo.add_edge(v[i].ff.ff , v[i].ff.ss , v[i].ss);
	}
	cout << algo.find_max_flow() << endl;
}