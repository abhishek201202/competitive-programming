#include<bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
using namespace std;

const int N = 1e6 + 5;
int n;
vector<int> adj[N];
int col[N];

// Using DFS
bool is_bipartiteDFS(){
	bool okk = true;
	function<void(int, int)> dfs = [&](int u, int p){
		if(p == -1) col[u] = 1;
	    else col[u] = col[p] ^ 3;
	    for(int v : adj[u]){
	        if(!col[v]){
	            dfs(v, u);
	        }else{
	            if(col[v] == col[u]) okk = false;
	        }
	    }
	};
	for(int i = 0; i < n; i++){
		if(!col[i]) dfs(i, -1);
	}
	return okk;
}



// Using BFS
bool is_bipartiteBFS(){
	bool okk = true;
	for(int i = 0 ; i < n ;i++){
		if(!col[i]){
			queue<int> q;
			q.push(i);
			col[i] = 1;
			while(q.size()){
				int u = q.front();  q.pop();
				for(auto v : adj[u]){
					if(!col[v]){
						col[v] = col[u] ^ 3  ,  q.push(v);
					}else{
						okk &= ( col[v] == (col[u] ^ 3) );
					}
				}
			}
		}
	}
	return okk;
}



int main(){
	cin >> n;
	for(int i = 0 ; i < n - 1 ; i++){
		int s , d; cin >> s >> d;
		adj[s - 1].pb(d - 1);
		adj[d - 1].pb(s - 1);
	}

}