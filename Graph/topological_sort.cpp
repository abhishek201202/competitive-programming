#include<bits/stdc++.h>
#define int long long
#define ff first 
#define ss second
#define pb push_back
using namespace std;


const int N = 1e5 + 5;
int n;
vector<int> adj[N];
int visited[N], in[N];


// By Using DFS
vector<int> topological(){
	memset(visited , 0 , sizeof(visited));
	vector<int> ans;
	function<void(int, int)> dfs = [&](int u, int p){
		visited[u] = 1;
		for(auto v : adj[u]){
			if(visited[v]) continue;
			dfs(v, u);
		}
		ans.pb(u);
	};

	for(int i = 0 ; i < n ; i++){
		if(!visited[i]){
			dfs(i, -1);
		}
	}
	reverse(ans.begin() , ans.end());
	return ans;
}

// By Using BFS
vector<int> khans_algo(){
	queue<int> q;
	for(int i = 0; i < n; i++){
		if(!in[i]) q.push(i);
	}
	vector<int> res;
	int cnt = 0;
	while(q.size() != 0){
		int u = q.front();
		q.pop();
		res.push_back(u);
		for(auto v : adj[u]){
			in[v]--;
			if(!in[v]) q.push(v);
		}
		cnt++;
	}
	if(cnt == 0) res.clear(); // there exits a cycle
	return res;
}


int32_t main(){
	cin >> n;
	for(int i = 0 ; i < n - 1 ; i++){
		int s , d; cin >> s >> d;
		adj[s - 1].pb(d - 1);
		in[s - 1]++;
	}
}