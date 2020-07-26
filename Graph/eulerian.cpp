// Hierholzer’s Algorithm
#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first 
#define ss second
using namespace std;

const int N = 1e5;
vector<int> adj[N];
int out[N];
int n , m; 

// All the Edges are in same connected component 
// for both directed and undirected graph

// For Directed Graph
// Eulerian Path    :: at most 1 vertex has (out - in == 1)
//                     at most 1 vertex has (in - out == 1)
//                     all other vertices have equal in and out degree
// ((sv = out - in == 1) && (ev == in - out == 1)) when exactly 2 vertex are odd
// Eulerian Circuit :: every vertex has equal in and out degree

// For Undirected Graph
// Eulerian Path    :: either every vertex has even degree 
//                     or exactly 2 vertices have odd degree 
// Eulerian Circuit :: every vertex has an even degree


// For directed graph
vector<int> eulerian(){
	vector<int> path;
	stack<int> st;
	st.push(0);
	while(st.size() != 0){
		int u = st.top();
		if(!out[u]){
			st.pop();
			path.pb(u);
		}else{
			if(adj[u].size()){
				out[u]--;
				int v = adj[u].back();
				st.push(v);
				adj[u].pop_back();
			}
		}
	}
	reverse(path.begin() , path.end());
	return path;
}

int32_t main(){
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int x ,y; cin >> x >> y;
		adj[x - 1].pb(y - 1);
		out[x - 1]++;
	}

	vector<int> P = eulerian();
	for(int i = 0; i < P.size() ; i++){
		cout << P[i] + 1 << " ";
	}
	cout << endl;
}