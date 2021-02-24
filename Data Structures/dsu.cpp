#include<bits/stdc++.h>
#define int long long
#define ff first
#define ss second
#define pb push_back
using namespace std;
typedef pair<int,int> pii;

template<typename T>
struct DSU{
	int Size;
	map<T,T> parent;
	map<T, int> Rank;
	DSU() : Size(0){}

	int size(){ return Size; }
	
	void init(int u){
		if(parent.count(u)) return;
		parent[u] = u;
		Rank[u] = 0; 
		Size++;
	}
	
	T find(T u){
		if(u == parent[u]) return u;
		return parent[u] = find(parent[u]) ;
	}
	
	void merge(T u , T v){
		init(u); init(v);
		u = find(u);
		v = find(v);
		if(u != v){
			if(Rank[u] < Rank[v]){
				swap(u, v);
			}
			parent[u] = v;
			if(Rank[u] == Rank[v]) Rank[u]++;
			Size--;
		}
	}
	
	map<T, vector<T>> get_comp(){
        map<T, vector<T>> comp;
        for(auto &[f, s] : parent){
            parent[f] = find(f);
            comp[parent[f]].push_back(f);
        }
        return comp;
    }
};


int32_t main(){
	DSU<int> dsu;
	
}