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
int n , m ;

class cmp{
public:
	bool operator()(pii a , pii b){
		return a.ss > b.ss;
	}
};

// single source shortest path
// applicable for -ve weighted graph as well
// using visited array will lead to wrong result.....
// as in this case some we might miss to relax some of the edges
// return weather it contain a negative cycle or not....[1 -> Yes]....[0 -> No]
bool bellman_ford(int s){
	for(int i = 0 ; i < n ; i++) dis[i] = 1e8;
	dis[s] = 0;
	for(int i = 0 ; i < n; i ++){
		priority_queue<pii , vector<pii> , cmp> pq;
		pq.push({s , 0});
		bool no_change = true;
		while(pq.size() != 0){
			pii curr = pq.top();
			pq.pop();
			int u = curr.ff;
			for(int i = 0 ; i < adj[u].size() ; i++){
				int v = adj[u][i];
				if(dis[v] > dis[u] + weight[u][i] && weight[u][i] != 0){
					dis[v] = dis[u] + weight[u][i];
					pq.push({v , dis[v]});
					no_change = false;
				}
			}
		}
		if(no_change) break;
		if(i == n - 1 && !no_change) return true;
	}
	return true
}


int32_t main(){
	cin >> n >> m;
	for(int i = 0 ; i < m ; i++){
		int x, y , w; cin >> x >> y >> w;
		adj[x - 1].pb(y - 1);
		weight[x - 1].pb(w);
	}
	bellman_ford(0);
	for(int i = 0 ;i < n ; i++){
		cout << i << " " << dis[i] << endl;
	}
}
/*
6 9
1 2 6
1 3 4
1 4 5
4 3 -2
3 2 -2
2 5 -1
3 5 3
4 6 -1
5 6 3
*/