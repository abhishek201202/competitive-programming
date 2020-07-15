#include<bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define int long long
using namespace std;

const int N = 1e3;
vector<int> adj[N] , weight[N];
int dp[N][N];
int n , m;

void flyod(){
	for(int i = 0 ;i < n;  i++){
		for(int j = 0 ; j < n ;j++){
			dp[i][j] = (i == j) ? 0 : 1e8;
		}
	}
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < adj[i].size() ; j++){
			int u = i , v = adj[u][j];
			dp[u][v] = weight[u][j];
		}
	}
	for(int K = 0 ; K < n ; K ++){
		for(int i = 0 ; i < n ; i++){
			for(int j = 0; j < n ; j++){
				dp[i][j] = min(dp[i][j] , dp[i][K] + dp[K][j]);
				// K == i === >>> min(dp[i][j] , dp[i][i] + dp[i][j])
				// === >>> dp[i][i] = 0 === >>> dp[i][j] = dp[i][j] 
			}
		}
	}
}


int32_t main(){
	cin >> n >> m;
	for(int i = 0 ;i < m ;i ++){
		int s , d , w; cin >> s >> d >> w;
		adj[s - 1].pb(d - 1);
		weight[s - 1].pb(w);
	}
	flyod();
	for(int i = 0 ;i  < n ; i ++){
		for(int j = 0; j < n ; j++){
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
}
/*
4 6
1 2 9
2 1 6
1 3 -4
4 3 1
3 2 5
2 4 2
*/