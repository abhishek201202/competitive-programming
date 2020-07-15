#include<bits/stdc++.h>
#define int long long
#define ff first
#define ss second
#define pb push_back
using namespace std;
typedef pair<int,int> pii;

template<typename T>
struct DSU{
	map<T,T> parent;
	
	void make_set(T u){
		parent[u] = u;
	}

	T get_parent(T u){
		if(u == parent[u]) return u;
		return parent[u] = get_parent(parent[u]) ;
	}
	void merge(T u , T v){
		if(!(parent.count(u)>0)) make_set(u);
		if(!(parent.count(v)>0)) make_set(v);
		T p_u = get_parent(u);
		T p_v = get_parent(v);
		if(p_v!=p_u){
			parent[p_u] = p_v;
		}
	}
};


int32_t main(){
	DSU<int> dsu;
	for(int i = 0 ; i < n ; i++){
		dsu.make_set(i);
	}
}

/*
8 2
3 47
6 13
4 47
7 39
8 24
7 23
7 35
4 50
3 2
5 7
6 8
5 6
240
*/