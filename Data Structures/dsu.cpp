#include<bits/stdc++.h>
#define int long long
#define ff first
#define ss second
#define pb push_back
using namespace std;



struct DSU{
    int n, Size;
    vector<int> Parent, Rank;
    
    DSU(int _n){
        n = _n, Size = _n;
        Parent = vector<int>(n);
        Rank = vector<int>(n, 0);
        iota(Parent.begin(), Parent.end(), 0);
    }

    int size(){ return Size; }
    
    int find(int u){
        if(u == Parent[u]) return u;
        return Parent[u] = find(Parent[u]) ;
    }
    
    void merge(int u , int v){
        u = find(u);
        v = find(v);
        if(u != v){
            if(Rank[u] < Rank[v]){ // trying to minimize the height of the tree
                swap(u, v);
            }
            Parent[v] = u;
            if(Rank[u] == Rank[v]) Rank[u]++;
            Size--;
        }
    }
    
    unordered_map<int, vector<int>> get_comp(){
        unordered_map<int, vector<int>> comp;
        for(int i = 0; i < n; i++){
            Parent[i] = find(i);
            comp[Parent[i]].push_back(i);
        }
        return comp;
    }
};




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
