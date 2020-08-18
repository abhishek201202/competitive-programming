#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 3e5 + 5;
int n;
vector<int> adj[N];
int f[N], g[N], vis[N];
int diameter;

void dfs(int u){
	vis[u] = 1;
	vector<int> val;
	for(int v : adj[u]){
		if(vis[v]) continue;
		dfs(v);
		val.push_back(f[v]);
	}
	if(val.size()){
		sort(val.begin(), val.end(), greater<int>());
		f[u] = val[0] + 1;
	}
	if(val.size() >= 2){
		g[u] = val[0] + val[1] + 2;
	}
	diameter = max(diameter, max(f[u], g[u]));
}



int32_t main(){
	cin >> n;
	for(int i = 0; i < n - 1; i++){
		int s, d; cin >> s >> d;
		adj[s - 1].push_back(d - 1);
		adj[d - 1].push_back(s - 1);
	}
	dfs(0);
	cout << 3 * diameter << endl;
}