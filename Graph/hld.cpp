// abhishek soni.....[NSIT'22]
#include<bits/stdc++.h>
#include<cstdio>
#include<vector>
#define endl '\n'
#define ff first
#define ss second
#define pb push_back
using namespace std;
typedef pair<int,int> pii;

const int H = 14;
const int N = 10100;
int n;
vector<int> adj[N] , weight[N] , indexx[N];                         // tree 
int parent[N][H] , depth[N];                                        // lca 
int chainNo , chainH[N] , chainInd[N] , subsize[N] , otherEnd[N];   // hld
int ptr , baseArr[N] , basePos[N];                                  // seg. tree
// weight[u][i]  == weight of edge b/w u and its ith childen
// indexx[u][i]  == indexx of edge b/w u and its ith children
                                 
// chainNo       == total no of chain == depend upon the tree
// chainH[u]     == head of the chain whose u is a part
// chainInd[u]   == chain no. of uth node 
// otherEnd[ith] == lower node of ith edge

// baseArr       == store all the seg. tree in a single array for Q process.
// baseArr[ith]  == basePos[ith] pe jo node hai uske uppar waali edge
// basePos[u]    == pos of the uth node in base array
// ptr           == length of baseArr == n
void init(){
	for(int i = 0 ; i  < N ;i++){
		for(int j = 0; j  < H ; j++){
			parent[i][j] = -1;
		}
		depth[i] = 0;
		
		adj[i].clear();
		weight[i].clear();
		indexx[i].clear();
		
		chainH[i] = -1;
		chainInd[i] = 0;
		subsize[i] = 0;
		otherEnd[i] = 0;

		basePos[i] = 0;
		baseArr[i] = 0;
	}
	chainNo = 0 , ptr = 0;
}














/*
 * LCA start  **********************************************
 */
void dfs(int u , int par = -1){
	parent[u][0] = par; 
	depth[u] = (par == -1)? 0 : depth[par] + 1;
	subsize[u] = 1;
	for(int i = 0 ; i < adj[u].size() ; i++){
		int v = adj[u][i];
		if(v == par) continue;
		otherEnd[indexx[u][i]] = v;
		dfs(v , u);
		subsize[u] += subsize[v];
	}
}
void lca_pre(int n){
	for(int i = 1; i < H ; i++){
		for(int node = 0 ; node < n ; node++){
			if(parent[node][i - 1] == -1) continue;
			parent[node][i] = parent[parent[node][i - 1]][i - 1];
		}
	}
}
int lca(int u , int v){
	if(depth[u] > depth[v]) swap(u , v);
	int diff = depth[v] - depth[u];
	for(int i = 0 ; i < H ; i++){
		if((diff >> i) & 1) v = parent[v][i];
	}
	if(u == v) return u;
	for(int i = H - 1 ; i >= 0 ; i--){
		if(parent[u][i] == parent[v][i]) continue;
		u = parent[u][i];
		v = parent[v][i];
	}
	// now we are just one hoop below the lca
	return parent[u][0];
}
// all correct tested on E-Tree Queries [codeforces]
/*
 * LCA over **********************************************
 */





















/*
 * sement tree start *************************************
 */

template<typename T>
struct segment_tree{
	vector<int> arr;
	vector<T> tree;
	
	void init(int* arr , int n){
		this->arr.resize(n , 0);
		this->tree.resize(4*n , 0);
		for(int i = 0; i < n ; i++){
			this->arr[i] = arr[i];
		}
	}

	void build(int node , int si ,int ei){
		if(si == ei){
			tree[node] = arr[si];
			return;
		}
		int mid = (si + ei)/2;
		build(2 * node , si , mid);
		build(2 * node + 1 , mid + 1 , ei);
		tree[node] = max(tree[2*node] , tree[2*node + 1]);
	}

	int query(int node , int si , int ei , int l , int r){
		if(l > r) swap(l , r);
		if(ei < l || si > r){
			return 0; 
		}
		if(l <= si && r >= ei){
			return tree[node];
		}
		int mid = (si + ei)/2;
		int left = query(2 * node , si , mid , l , r);
		int right = query(2 * node + 1 , mid + 1 , ei , l , r);
		return max(left , right);
	}

	void update(int node , int si , int ei , int index , int val){
		if(si == ei){
			tree[node] = val;
			arr[index] = val;
			return;
		}
		int mid = (si + ei)/2;
		if(index <= mid){
			update(2 * node , si , mid , index , val);
		}else{
			update(2 * node + 1 , mid + 1 , ei , index , val);
		}
		tree[node] = max(tree[2 * node] , tree[2 * node + 1]);
	}

};
segment_tree<int> seg;
// all correct tested on coding ninjas
/*
 * segment tree over *************************************
 */


















/*
 * HLD start **********************************************
 */
void hld(int u , int par = -1ll , int W = -1ll){
	if(chainH[chainNo] == -1){
		chainH[chainNo] = u;
	}
	chainInd[u] = chainNo;
	basePos[u] = ptr;
	baseArr[ptr++] = W;
	int sc = -1 , curr_size = 0 , new_weight = 0;
	for(int i = 0 ; i < adj[u].size() ; i++){
		int v = adj[u][i];
		if(v == par) continue;
		if(subsize[v] > curr_size){
			curr_size = subsize[v];
			sc = v;
			new_weight = weight[u][i];
		}
	}
	if(sc != -1) hld(sc , u , new_weight);
	for(int i = 0 ;i < adj[u].size() ;i++){
		int v = adj[u][i];
		if(v == sc || v == par) continue;
		chainNo++;
		hld(v , u , weight[u][i]);
	}
}

int query(int u , int v){
	auto Q = [&](int& u , int& v)->int{
		if(u == v) return 0;
		int uchain , vchain = chainInd[v] , ans = -1ll;
		while(1){
			if(u == -1) break;
			uchain = chainInd[u];
			if(uchain == vchain){
				if(u == v) break;
				ans = max(ans , seg.query(1 , 0 , n - 1 , basePos[v] , basePos[u] ));
				break;
			}else{
				ans = max(ans , seg.query(1 , 0 , n - 1 , basePos[chainH[uchain]] , basePos[u] ));
				u = chainH[uchain];
				u = parent[u][0]; // shift to next chain
			}
		}
		return ans;

	};
	int parr = lca(u,v);
	int ans1 = Q(u , parr);
	int ans2 = Q(v , parr);
	return max(ans1 , ans2);
}

void update(int ith , int val){
	seg.update(1 , 0 , n - 1 , basePos[otherEnd[ith]] , val);
}
void run_hld(int n){
	dfs(0);
	lca_pre(n);
	hld(0);
	seg.init(baseArr , n);
	seg.build(1 , 0 , n - 1);
}
// not tested yet 
/*
 * HLD over **********************************************
 */



















/*
 * main function *****************************************
 */
int main(){
	int t = 1;
	scanf("%d " , &t);
	while(t--){
		init();

		scanf("%d" , &n);
		for(int i = 0 ; i  < n - 1 ; i++){
			int s ,d ,w ;
			scanf("%d %d %d" , &s , &d , &w);
			
			adj[s - 1].pb(d - 1);
			adj[d - 1].pb(s - 1);
			
			weight[s - 1].pb(w);
			weight[d - 1].pb(w);
			
			indexx[s - 1].pb(i);
			indexx[d - 1].pb(i);
		}

		run_hld(n);

		while(1){
			char s[100]; scanf("%s" , &s);
			if(s[0] == 'Q'){
				int a , b ; 
				scanf("%d %d" , &a , &b);
				printf("%d\n" , query(a - 1 , b - 1));
			}else if(s[0] == 'C'){
				int ith , w;
				scanf("%d %d" , &ith , &w);
				update(ith - 1, w);
			}else{
				break;
			}
		}

	}
}