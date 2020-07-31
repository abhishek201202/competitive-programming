#include<bits/stdc++.h>
#define int long long
#define ff first
#define ss second
#define pb push_back
using namespace std;
typedef pair<int,int> pii;

template<typename T>
struct DSU{
	int sz;
	map<T,T> parent;
	DSU(){}
	DSU(int n){
		this -> sz = n;
		for(int i = 0; i < n; i++){
			parent[i] = i;
		}
	}
	T find(T u){
		if(!parent.count(u)) return parent[u] = u;
		if(u == parent[u]) return u;
		return parent[u] = find(parent[u]) ;
	}
	void merge(T u , T v){
		if(!parent.count(u)) parent[u] = u;
		if(!parent.count(v)) parent[v] = v;
		T p_u = find(u);
		T p_v = find(v);
		if(p_v != p_u){
			parent[p_u] = p_v;
			sz--;
		}
	}
	int size(){ 
		return sz;
	}
};


int32_t main(){
	DSU<int> dsu;
	
}