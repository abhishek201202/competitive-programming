// Maxuimum Bipartitie Matching | Using maxflow algorithm
// Time Complexity :: O(VE)
#include<bits/stdc++.h>
#define int long long
#define ff first
#define ss second
using namespace std;

const int N = 1e5 + 5;
int n, m;
vector<vector<int>> adj;

// adj[i][j] :: there is edge b/w node i and j if it is 1
struct BipartitieMatching{
	int n, m;
	vector<vector<int>> adj;
	vector<int> L, R, vis;
	BipartitieMatching(vector<vector<int>> &adj, int n, int m){
		this -> adj = adj;
		L.resize(n, -1);
		R.resize(m, -1);
		vis.resize(m);
		this -> n = n, this -> m = m;
	}

	bool Match(int u){
		for(int v = 0; v < m; v++){
			if(adj[u][v] && !vis[v]){
				vis[v] = true;
				if(R[v] < 0 || Match(R[v])){
					L[u] = v;
					R[v] = u;
					return true;
				}
			}
		}
		return false;
	}

	int Flow(){
		int F = 0;
		for(int u = 0; u < n; u++){
			// when we u have to reinitialize your vector
			// try to use fill() , resize will give wrong answer 
			fill(vis.begin(), vis.end(), 0);
			if(Match(u)) F++;
		}
		return F;
	}
};


int32_t main(){
	int tt; cin >> tt;
	while(tt--){
		cin >> n >> m;
		adj.resize(n, vector<int>(m));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> adj[i][j];
			}
		}
		BipartitieMatching bpm(adj, n, m);
		cout << bpm.Flow() << endl;
	}
}