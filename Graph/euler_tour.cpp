// Euler Tour
#include <bits/stdc++.h>
#define ff first
#define ss second
#define int long long
#define pb push_back
using namespace std;

const int N   = 5e5 + 5;
int n, idx;
vector<int> adj[N];
int order[N], vis[N];

void Euler_tour(int u){
	vis[u] = 1;
	order[idx++] = u;
	for(auto v : adj[u]){
		if(vis[v]) continue;
		Euler_tour(v);
		order[idx++] = u;
	}
}

int32_t main(){
	int tt = 1;
	cin >> tt;
	while(tt--){
		idx = 0;
		for(int i = 0; i < n; i++){
			adj[i].clear();
		}
		memset(order, 0, sizeof order);
		memset(vis, 0, sizeof vis);

		cin >> n;
		for(int i = 0; i < n - 1; i++){
			int x, y; cin >> x >> y;
			adj[x - 1].push_back(y - 1);
			adj[y - 1].push_back(x - 1);
		}
		Euler_tour(0);
		for(int i = 0; i < 2 * n - 1; i++){
			cout << order[i] + 1 << " ";
		}
		cout << endl;
	}
}