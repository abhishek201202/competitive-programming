// https://cses.fi/problemset/task/1684
#include<bits/stdc++.h>
using namespace std;

struct TwoSat{
    int n;
    vector<vector<int>> adj, adjT;
    vector<int> comp, topo, res; // comp[u] : Id of the SCC containing node u
    vector<bool> vis;
    
    TwoSat(){}
    TwoSat(int _n){ init(_n); }

    void init(int _n){
        this -> n = _n;
        adj.assign(2 * n, vector<int>());
        adjT.assign(2 * n, vector<int>());
        comp.resize(2 * n);
        vis.resize(2 * n);
        res.resize(2 * n);
    }

    // 0 based indexing 
    void add_edge(int u, int v){
        adj[u].push_back(v);
        adjT[v].push_back(u);
    }
    // For the following three functions
    // int x, bool val: if 'val' is true, we take the variable to be x. Otherwise we take it to be x's complement.


    // At least one of them is true
    void add_clause_or(int u, bool val1, int v, bool val2){
        add_edge(u + (val1 ? n : 0), v + (val2 ? 0 : n));
        add_edge(v + (val2 ? n : 0), u + (val1 ? 0 : n));
    }

    // Only one of them is true
    void add_clause_xor(int u, bool val1, int v, bool val2){
        add_clause_or(u, val1, v, val2);
        add_clause_or(u, !val1, v, !val2);
    }

    // Both of them has the same value
    void add_clause_and(int u, bool val1, int v, bool val2){
        add_clause_xor(u, !val1, v, val2);
    }

    // Topological Sort
    void dfs(int u){
        vis[u] = true;
        for(int v : adj[u]){
            if(!vis[v]) dfs(v);
        }
        topo.push_back(u);
    }

    // Extracting Strongly connected component
    void scc(int u, int id){
        vis[u] = true;
        comp[u] = id;
        for(int v : adjT[u]){
            if(!vis[v]) scc(v, id);
        }
    }

    // Returns true if the proposition is satisfiable and contructs a valid assignment
    bool satisfiable(){
        fill(vis.begin(), vis.end(), false);
        for(int i = 0; i < 2 * n; i++){
            if(!vis[i]) dfs(i);
        }
        reverse(topo.begin(), topo.end());

        fill(vis.begin(), vis.end(), false);
        int id = 0;
        for(int u : topo){
            if(!vis[u]) scc(u, id++);
        }

        // constructing the answer
        for(int i = 0; i < n; i++){
            if(comp[i] == comp[i + n]) return false;
            res[i] = (comp[i] > comp[i + n] ? 1 : 0);
        }
        return true;
    }
};



int32_t main(){
    int n, m; cin >> n >> m;

    TwoSat ts(m);
    for(int i = 0; i < n; i++){
        char pref1, pref2;
        int u, v;
        cin >> pref1 >> u >> pref2 >> v;
        ts.add_clause_or(u - 1, pref1 == '+', v - 1, pref2 == '+');
    }
    if(!ts.satisfiable()){
        cout << "IMPOSSIBLE" << endl;
    }else{
        for(int i = 0; i < m; i++){
            cout << (ts.res[i] ? '+' : '-') << " ";
        }
        cout << endl;
    }
}