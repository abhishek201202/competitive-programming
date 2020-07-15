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

// condition of Eulerian Path :
// directed === >>> at most 1 vertex has (out - in == 1)
//                  at most 1 vertex has (in - out == 1)
//                  all other vertices have equal in and out degree
// undirected === >>> either every certex has even degree or exactly 
//                    2 vertices have odd degree



// Condtion for Eulerian Circuit:
// directed -> every vertex has equal in and out degree
// undirected -> every vertex has an even degree

// this is for directed graph
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
/*
6 12
1 2 
1 3
2 2 
2 4
2 4
3 2
3 1
3 5
4 3
4 6 
5 6
6 3
output : 1 3 5 6 3 1 2 4 3 2 2 4 6
*/
/*
4 4
1 2 
1 2
1 3
2 3
*/