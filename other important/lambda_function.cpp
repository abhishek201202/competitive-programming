// lambda function
#include <bits/stdc++.h>
#define endl "\n"
#define ff first
#define ss second
#define pb push_back
#define int long long
using namespace std;

const int N = 1e5 + 5;
int n , depth[N] , col[N];
vector<int> adj[N];

int g(int n, auto& f){
	return f(n);
}

int32_t main(){
	cin >> n;
	for(int i = 0 ;i < n - 1; i++){
		int x, y; cin >> x >> y;
		adj[x - 1].pb(y - 1);
		adj[y - 1].pb(x - 1);
	}
	for(int i = 0 ;i < n ; i++){
		cin >> col[i];
	}
	// lambda function in sorting
	sort(col , col + n , [&](int a , int b){
		return a < b;
	});

	// lambda function , if we want to use recursion
	// function<return_type(input parameter)>
	function<void(int, int)> dfs = [&](int u , int p = -1){
		if(p != -1){
			depth[u] = depth[p] + 1;
		}
		for(auto v : adj[u]){
			if(v == p) continue;
			dfs(v, u);
		}
	};


	//passing lambda function as an argument
	int n = 1323;
	auto f = [&](int n){
    	return n * 10;
    };
    cout << g(n, f) << endl;
}