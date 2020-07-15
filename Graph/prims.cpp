#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first 
#define ss second
using namespace std;
typedef pair<int,int> pii;

const int N = 1e6;
vector<int> adj[N] , weight[N];
int par[N] , dis[N] , vis[N];
int n , m;

class cmp{
public:
	bool operator()(pii a , pii b){
		return a.ss > b.ss;
	}
};

void prims(){
	for(int i = 0; i < n ; i ++){
		par[i] = -1; dis[i] = 1e8; vis[i] = false;
	}
	dis[0] = 0;
	
	priority_queue<pii , vector<pii> , cmp> pq;
	pq.push({0 , 0});
	while(pq.size() != 0){
		pii curr = pq.top();
		pq.pop();
		int u = curr.ff;
		vis[u] = true;
		for(int i =  0 ; i < adj[u].size() ;i ++){
			int v = adj[u][i];
			int w = weight[u][i];
			if(vis[v]) continue;
			if(dis[v] >= w && w != 0){
				dis[v] = w;
				par[v] = u;
				pq.push({v , dis[v]});
			}
		}
	}
}

int32_t main(){
	cin >> n >> m;
	for(int i = 0; i < m ; i++){
		int x , y ,w; cin >> x >> y >> w;
		x ++ , y ++ ;
		adj[x - 1].pb(y - 1);
		adj[y - 1].pb(x - 1);

		weight[x - 1].pb(w);
		weight[y - 1].pb(w);
	}
	prims();
	for(int i = 1; i < n ;i++){
		int u = i , v = par[u];
		cout << min(u , v) << " " << max(u , v) << " " << dis[u] << endl;
	}
}
/*
buttefuly structure [CrO_5]
6 7
0 3 5
0 2 7
0 5 1
0 1 2
0 4 4
2 3 1
1 5 0
*/