#include<bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
#define int long long
#define pii pair<int,int>
using namespace std;

const int N = 1e5;
vector<int> adj[N] , weight[N];
int dis[N];
int n , m;

class cmp{
public:
	bool operator()(pii a , pii b){
		return a.ss > b.ss;
	}
};

// single source shortest path 
// not work for negative weighted graph
void dijkstra(int s){
	for(int i = 0 ; i < n ; i++) dis[i] = 1e8;
	dis[s] = 0;

	priority_queue<pii , vector<pii> , cmp> pq;
	pq.push({s , 0});
	
	while(pq.size() != 0){
		pii curr = pq.top();
		pq.pop();
		int u = curr.ff;
		for(int i = 0 ; i < adj[u].size() ; i++){
			int v = adj[u][i];
			if(dis[v] > dis[u] + weight[u][i] && weight[u][i] != 0){
				dis[v] = dis[u] + weight[u][i];
				pq.push({v , dis[v]});
			}
		}
	}
}

int32_t main(){
	cin >> n >> m;
	for(int i = 0; i < m ;  i++){
		int x ,y ,w; cin >> x >> y >> w;
		x++; y++;
		adj[x - 1].pb(y - 1);
		adj[y - 1].pb(x - 1);

		weight[x - 1].pb(w);
		weight[y - 1].pb(w);
	}
	dijkstra(0);
	for(int i = 0 ;i < n ; i++){
		cout << i << " " << dis[i] << endl;
	}

}