#include<bits/stdc++.h>
using namespace std;

class edge{
	public:
	int s , d , w;
};
const int N = 1e5;
vector<edge> E , output;
int par[N];
int n , m; 


int find_set(int u){
	if(u == par[u]) return u;
	else return par[u] = find_set(par[u]);
}
void union_set(int u , int v){
	int pu = find_set(u) , pv = find_set(v);
	if(pu != pv){
		par[pu] = pv;
	}
}

void kruskal(){
	sort(E.begin() , E.end() ,[&](edge a , edge b){
		return a.w < b.w;
	});
	for(int i = 0; i < n ; i++){
		par[i] = i;
	}

	int i = 0 , j = 0;
	while(j < n - 1){
		int u = E[i].s;
		int v = E[i].d;
		if(find_set(u) != find_set(v)){
			union_set(u , v);
			output[j++] = E[i];
		}
		i++;
	}
}

int32_t main(){
	cin >> n >> m;
	E.resize(m); output.resize(n - 1);
	for(int i = 0; i < m ; i++){
		cin >> E[i].s >> E[i].d >> E[i].w;
	}
	kruskal();
	for(int i = 0 ; i < n - 1 ;i ++){
		cout << min(output[i].s , output[i].d) << " " << max(output[i].s , output[i].d) << " " << output[i].w << endl;
	}
}