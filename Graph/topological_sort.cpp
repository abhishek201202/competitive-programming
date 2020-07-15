#include<bits/stdc++.h>
#define int long long
#define ff first 
#define ss second
#define pb push_back
using namespace std;


const int N = 1e5 + 5;
int n;
vector<int> adj[N];
int visited[N];
vector<int> ans;


void dfs(int u , int p = -1){
	visited[u] = 1;
	for(auto v : adj[u]){
		if(visited[v]) continue;
		dfs((v , u));
	}
	ans.pb(u);
}

void topological(){
	ans.resize(0);
	memset(visited , 0 , sizeof(visited));
	for(int i = 0 ; i < n ; i++){
		if(!visited[i]){
			dfs(i);
		}
	}
	reverse(ans.begin() , ans.end());
}

int32_t main(){
	cin >> n;
	for(int i = 0 ; i < n - 1 ; i++){
		int s , d; cin >> s >> d;
		adj[s - 1].pb(d - 1);
		adj[d - 1].pb(s - 1);
	}
}